/**
 * (c) 2009, Tonnerre Lombard <tonnerre@NetBSD.org>,
 *	     The NetBSD Foundation. All rights reserved.
 *
 * Redistribution and use in source  and binary forms, with or without
 * modification, are permitted  provided that the following conditions
 * are met:
 *
 * * Redistributions of  source code  must retain the  above copyright
 *   notice, this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright
 *   notice, this  list of conditions and the  following disclaimer in
 *   the  documentation  and/or  other  materials  provided  with  the
 *   distribution.
 * * Neither the name of the The NetBSD Foundation nor the name of its
 *   contributors may  be used to endorse or  promote products derived
 *   from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS"  AND ANY EXPRESS  OR IMPLIED WARRANTIES  OF MERCHANTABILITY
 * AND FITNESS  FOR A PARTICULAR  PURPOSE ARE DISCLAIMED. IN  NO EVENT
 * SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL,  EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED  TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE,  DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT  LIABILITY,  OR  TORT  (INCLUDING NEGLIGENCE  OR  OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * $NetBSD: pam_mkhomedir.c,v 1.1.1.1 2009/02/15 20:16:08 tonnerre Exp $
 */

#include <sys/types.h>
#include <security/pam_appl.h>
#include <security/pam_modules.h>

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <pwd.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <dirent.h>
#include <syslog.h>

#include <sys/stat.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>

static int
pam_mkhd_copy(pam_handle_t *pamh, const struct passwd *pwent,
	const char *from, const char *to)
{
	char *newfrom, *newto;
	struct dirent *dentry;
	struct stat di;
	ssize_t len;
	DIR *dirp;
	int ffd, tfd, ret;

	if (lstat(from, &di))
	{
		pam_error(pamh, "Unable to stat %s: %s", from, strerror(errno));
		return PAM_PERM_DENIED;
	}

	if (S_ISDIR(di.st_mode))
	{
		if (mkdir(to, di.st_mode & 07777))
		{
			pam_error(pamh, "Creating directory %s failed: %s",
				to, strerror(errno));
			return PAM_PERM_DENIED;
		}

		if (chown(to, pwent->pw_uid, pwent->pw_gid))
		{
			pam_error(pamh, "Setting ownership of %s failed: %s",
				to, strerror(errno));
			return PAM_PERM_DENIED;
		}

		dirp = opendir(from);
		if (!dirp)
		{
			pam_error(pamh, "Unable to open %s: %s", from,
				strerror(errno));
			return PAM_PERM_DENIED;
		}

		while ((dentry = readdir(dirp)))
		{
			if (dentry->d_name[0] == '.' &&
			    (dentry->d_name[1] == '\0' ||
				(dentry->d_name[1] == '.' &&
				 dentry->d_name[2] == '\0')))
				continue;

			newfrom = malloc(strlen(from) + strlen(dentry->d_name) +
				2);
			if (!newfrom)
			{
				closedir(dirp);
				return PAM_PERM_DENIED;
			}

			memset(newfrom, 0, strlen(from) + strlen(dentry->d_name) + 2);
			strlcpy(newfrom, from, strlen(from) + 1);
			newfrom[strlen(from)] = '/';
			strlcpy(newfrom + strlen(from) + 1, dentry->d_name, strlen(dentry->d_name) + 1);
			newfrom[strlen(from) + strlen(dentry->d_name) + 2] =
				'\0';

			newto = malloc(strlen(to) + strlen(dentry->d_name) + 2);
			if (!newto)
			{
				free(newfrom);
				closedir(dirp);
				return PAM_PERM_DENIED;
			}

			strlcpy(newto, to, strlen(to) + 1);
			newto[strlen(to)] = '/';
			strlcpy(newto + strlen(to) + 1, dentry->d_name, strlen(dentry->d_name) + 1);
			newto[strlen(to) + strlen(dentry->d_name) + 2] = '\0';

			ret = pam_mkhd_copy(pamh, pwent, newfrom, newto);

			free(newto);
			free(newfrom);

			if (ret != PAM_SUCCESS)
			{
				closedir(dirp);
				return ret;
			}
		}

		closedir(dirp);
	}
	else if (S_ISLNK(di.st_mode))
	{
		newto = malloc(di.st_size) + 1;
		memset(newto, 0, di.st_size + 1);

		if (readlink(from, newto, di.st_size + 1) < 0)
		{
			pam_error(pamh, "Readlink on %s failed: %s", from,
				strerror(errno));
			free(newto);
			return PAM_PERM_DENIED;
		}

		if (symlink(newto, to))
		{
			pam_error(pamh, "Creating symlink %s failed: %s", to,
				strerror(errno));
			free(newto);
			return PAM_PERM_DENIED;
		}

		free(newto);

		if (lchmod(to, di.st_mode & 07777))
		{
			pam_error(pamh, "Changing permissions of symlink %s failed: %s",
				to, strerror(errno));
			return PAM_PERM_DENIED;
		}

		if (lchown(to, pwent->pw_uid, pwent->pw_gid))
		{
			pam_error(pamh, "Changing ownership of symlink %s failed: %s",
				to, strerror(errno));
			return PAM_PERM_DENIED;
		}
	}
	else if (S_ISREG(di.st_mode))
	{
		ffd = open(from, O_RDONLY, 0);
		if (ffd == -1)
		{
			pam_error(pamh, "Opening %s for reading failed: %s",
				from, strerror(errno));
			return PAM_PERM_DENIED;
		}

		tfd = open(to, O_WRONLY | O_CREAT | O_TRUNC, di.st_mode & 07777);
		if (ffd == -1)
		{
			pam_error(pamh, "Opening %s for writing failed: %s",
				to, strerror(errno));
			close(ffd);
			return PAM_PERM_DENIED;
		}

		newto = malloc(65536);
		if (!newto)
		{
			pam_error(pamh, "Unable to allocate buffer: %s",
				strerror(errno));
			close(tfd);
			close(ffd);
			return PAM_PERM_DENIED;
		}

		while ((len = read(ffd, newto, 65546)) > 0)
		{
			if (write(tfd, newto, len) == -1)
			{
				pam_error(pamh, "Unable to write to %s: %s",
					to, strerror(errno));
				free(newto);
				close(tfd);
				close(ffd);
				return PAM_PERM_DENIED;
			}
		}

		free(newto);
		if (len == -1)
		{
			pam_error(pamh, "Unable to read from %s: %s", from,
				strerror(errno));
			close(tfd);
			close(ffd);
			return PAM_PERM_DENIED;
		}

		if (close(tfd))
		{
			pam_error(pamh, "Unable to close %s: %s", to,
				strerror(errno));
			close(ffd);
			return PAM_PERM_DENIED;
		}

		if (close(ffd))
		{
			pam_error(pamh, "Unable to close %s: %s", from,
				strerror(errno));
			return PAM_PERM_DENIED;
		}

		if (chown(to, pwent->pw_uid, pwent->pw_gid))
		{
			pam_error(pamh, "Changing ownership of symlink %s failed: %s",
				to, strerror(errno));
			return PAM_PERM_DENIED;
		}
	}

	return PAM_SUCCESS;
}

PAM_EXTERN int
pam_sm_open_session(pam_handle_t *pamh, int flags,
		    int argc, const char **argv)
{
	const struct passwd *pwent;
	const char *user;
	struct stat di;
	void (*sh)(int);
	pid_t child;
	int res;

	/* Who are we talking about anyway? */
	res = pam_get_user(pamh, &user, NULL);
	if (res != PAM_SUCCESS)
		return res;

	/* Fetch passwd entry */
	pwent = getpwnam(user);
	if (!pwent)
	{
		pam_error(pamh, "User not found in passwd?");
		return PAM_CRED_INSUFFICIENT;
	}

	openlog("pam_mkhomedir", LOG_PID, LOG_AUTH);
	if (stat(pwent->pw_dir, &di))
		return pam_mkhd_copy(pamh, pwent, "/etc/skel", pwent->pw_dir);

	return PAM_SUCCESS;
}

PAM_EXTERN int
pam_sm_close_session(pam_handle_t *pamh, int flags,
		    int argc, const char **argv)
{
	(void) pamh; (void) flags; (void) argc; (void) argv;
	return PAM_SUCCESS;
}

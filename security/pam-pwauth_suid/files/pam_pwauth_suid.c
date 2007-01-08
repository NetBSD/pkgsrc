/* $NetBSD: pam_pwauth_suid.c,v 1.1.1.1 2007/01/08 18:39:44 drochner Exp $ */

#include <sys/types.h>
#include <security/pam_appl.h>
#include <security/pam_modules.h>

#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

static int
askhelper(const char *user, const char *pass)
{
	int fd[2];
	pid_t pid, rpid;
	ssize_t res;
	size_t pwlen;
	int s;

	if (pipe(fd) < 0)
		return errno;

	pid = vfork();
	switch (pid) {
		case -1:
			return errno;
		case 0: /* child, feed it through its stdin */
			(void)dup2(fd[0], STDIN_FILENO);
			(void)close(fd[0]);
			(void)close(fd[1]);
			execl(PATH_HELPER, PATH_HELPER, user, NULL);
			_exit(errno);
		default: /* parent */
			(void)close(fd[0]);
			break;
	}

	pwlen = strlen(pass);
	res = write(fd[1], pass, pwlen);
	if (res != pwlen)
		return (res == -1 ? errno : EIO);

	(void)close(fd[1]); /* now child gets an EOF */

	rpid = waitpid(pid, &s, 0);
	if (rpid != pid)
		return errno;
	if (!WIFEXITED(s) || WEXITSTATUS(s))
		return EAUTH;

	return 0;
}

PAM_EXTERN int
pam_sm_authenticate(pam_handle_t *pamh, int flags,
		    int argc, const char **argv)
{
	const char *user, *pass;
	int res;

	res = pam_get_user(pamh, &user, NULL);
	if (res != PAM_SUCCESS)
		return res;
	res = pam_get_authtok(pamh, PAM_AUTHTOK, &pass, NULL);
	if (res != PAM_SUCCESS)
		return res;

	if (askhelper(user, pass) != 0)
		return PAM_AUTH_ERR;

	return PAM_SUCCESS;
}

PAM_MODULE_ENTRY("pam_passwdhelper");

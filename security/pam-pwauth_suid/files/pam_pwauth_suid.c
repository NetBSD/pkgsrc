/* $NetBSD: pam_pwauth_suid.c,v 1.3 2008/07/17 18:00:58 drochner Exp $ */

#include <sys/types.h>
#define PAM_SM_AUTH
#include <security/pam_appl.h>
#include <security/pam_modules.h>

#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>

static int
askhelper(const char *user, const char *pass)
{
	int fd[2];
	sigset_t chldsig, omask;
	pid_t pid, rpid;
	ssize_t res;
	size_t pwlen;
	int err, s;

	if (pipe(fd) < 0)
		return errno;

	/* make sure only we get the exit status of the helper */
	sigemptyset(&chldsig);
	sigaddset(&chldsig, SIGCHLD);
	if (sigprocmask(SIG_BLOCK, &chldsig, &omask) < 0) {
		err = errno;
		goto error2;
	}

	pid = vfork();
	switch (pid) {
		case -1:
			err = errno;
			goto error;
		case 0: /* child, feed it through its stdin */
			(void)dup2(fd[0], STDIN_FILENO);
			(void)close(fd[0]);
			(void)close(fd[1]);
			execl(PATH_HELPER, PATH_HELPER, user, NULL);
			_exit(errno);
		default: /* parent */
			(void)close(fd[0]);
			fd[0] = -1;
			break;
	}

	pwlen = strlen(pass);
	res = write(fd[1], pass, pwlen);
	if (res != pwlen) {
		err = (res == -1 ? errno : EIO);
		goto error;
	}

	(void)close(fd[1]); /* now child gets an EOF */

	rpid = waitpid(pid, &s, 0);
	sigprocmask(SIG_SETMASK, &omask, 0);
	if (rpid != pid)
		return errno;
	if (!WIFEXITED(s) || WEXITSTATUS(s))
		return EAUTH;

	return 0;

error:
	sigprocmask(SIG_SETMASK, &omask, 0);
error2:
	if (fd[0] != -1)
		(void)close(fd[0]);
	(void)close(fd[1]);
	return err;
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

PAM_EXTERN int
pam_sm_setcred(pam_handle_t *pamh, int flags,
	       int argc, const char **argv)
{

	return PAM_SUCCESS;
}

PAM_MODULE_ENTRY("pam_passwdhelper");

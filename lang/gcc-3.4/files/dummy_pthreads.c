#include <pthread.h> 
#include <errno.h>

/*  These are some dummy replacements for functions missing in the pthread library */

int pthread_mutexattr_setprotocol(pthread_mutexattr_t *attr, int protocol) {
	return 0;
}

int pthread_mutexattr_getprioceiling(const pthread_mutexattr_t *attr, int *prioceiling) {
	return 0;
}

int
pthread_setschedparam(pthread_t thread, int policy,
    const struct sched_param *param)
{
        if (param == NULL || policy < SCHED_FIFO || policy > SCHED_RR)
                return EINVAL;
        if (param->sched_priority > 0 || policy != SCHED_RR)
                return ENOTSUP;
        return 0;
}

 
int pthread_mutexattr_setprioceiling(pthread_mutexattr_t *attr,
    int prioceiling)
{
	return 0;
}

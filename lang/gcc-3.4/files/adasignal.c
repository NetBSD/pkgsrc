#include <signal.h>

/* <signal.h> defines macros for a number of
   signal handling functions. Bindings are 
   provided here, that expand the macros,
   for use by the Ada RTS.   */

int adasigaddset(sigset_t *set, int signo) {
    return sigaddset(set, signo);
}

int adasigdelset(sigset_t *set, int signo) {
    return sigdelset(set, signo);
}

int adasigemptyset(sigset_t *set) {
    return sigemptyset(set);
}

int adasigfillset(sigset_t *set) {
    return sigfillset(set);
}

int adasigismember(sigset_t *set, int signo) {
    return sigismember(set, signo);
}

int adasigaction(int sig, const struct sigaction *act, struct sigaction *oact) {
    return sigaction(sig, act, oact);
}

int adasigwait(const sigset_t *set, int *sig) {
    return sigwait(set, sig);
}

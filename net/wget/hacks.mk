# $NetBSD: hacks.mk,v 1.1 2024/03/15 20:31:52 nia Exp $

.ifndef WGET_HACKS_MK

WGET_HACKS_MK=

.include "../../mk/bsd.fast.prefs.mk"

# There is a bug in the 10.4 SDK that causes struct __darwin_ucontext
# to be undefined when transcluding <sys/signal.h> via stdlib.h.
#
# This hack simply disables defining the mcontext_t typedefs, which
# has no negative effects on this version.
.if ${OPSYS} == "Darwin" && ${OPSYS_VERSION} < 100500
PKG_HACKS+=		tiger-signal-h
CPPFLAGS+=		-D_MCONTEXT_T=1
CPPFLAGS+=		-D_MCONTEXT64_T=1
CPPFLAGS+=		-D_UCONTEXT_T=1
CPPFLAGS+=		-D_UCONTEXT64_T=1
.endif
.endif

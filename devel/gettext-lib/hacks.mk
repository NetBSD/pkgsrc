# $NetBSD: hacks.mk,v 1.1 2023/11/05 21:53:40 nia Exp $

.if !defined(GETTEXT_LIB_HACKS_MK)
GETTEXT_LIB_HACKS_MK=	# defined

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "Darwin" && ${OPSYS_VERSION} < 100500
# There is a bug in the PowerPC SDK that causes struct __darwin_ucontext
# to be undefined when transcluding <sys/signal.h> via stdlib.h.
#
# This hack simply disables defining the mcontext_t typedefs, which
# has no negative effects on 10.4.
PKG_HACKS+=		powerpc-signalh
CPPFLAGS+=		-D_MCONTEXT_T=1
CPPFLAGS+=		-D_MCONTEXT64_T=1
CPPFLAGS+=		-D_UCONTEXT_T=1
CPPFLAGS+=		-D_UCONTEXT64_T=1
.endif

.endif	# GETTEXT_LIB_HACKS_MK

# $NetBSD: pax.mk,v 1.3 2016/05/27 08:33:00 leot Exp $
#
# Infrastructure support for binaries known to fail with PaX enabled.
#
# User-settable variables:
# TOOLS_PLATFORM.paxctl
#	The path to the paxctl(8) binary
#
# Package-settable variables:
#
# NOT_PAX_ASLR_SAFE
#	The list of binaries which do not support PaX ASLR.
#
# NOT_PAX_MPROTECT_SAFE
#	The list of binaries which do not support PaX MPROTECT.
#
# Keywords: aslr mprotect pax paxctl
#

.if !defined(PAX_MK)

. if defined(TOOLS_PLATFORM.paxctl)
PAXCTL=	${TOOLS_PLATFORM.paxctl}
.  if !empty(NOT_PAX_ASLR_SAFE)
_INSTALL_ALL_TARGETS+=		post-install-pax-aslr-binaries

.PHONY: post-install-pax-aslr-binaries
post-install: post-install-pax-aslr-binaries
post-install-pax-aslr-binaries:
	@${STEP_MSG} "Setting PaX ASLR flags"
	${RUN}								\
	for binary in ${NOT_PAX_ASLR_SAFE}; do				\
		${PAXCTL} +a ${DESTDIR}${PREFIX}/$$binary;		\
	done
.  endif

.  if !empty(NOT_PAX_MPROTECT_SAFE)
_INSTALL_ALL_TARGETS+=		post-install-pax-mprotect-binaries

.PHONY: post-install-pax-mprotect-binaries
post-install: post-install-pax-mprotect-binaries
post-install-pax-mprotect-binaries:
	@${STEP_MSG} "Setting PaX MPROTECT flags"
	${RUN}								\
	for binary in ${NOT_PAX_MPROTECT_SAFE}; do			\
		${PAXCTL} +m ${DESTDIR}${PREFIX}/$$binary;		\
	done
.  endif
. endif

.endif

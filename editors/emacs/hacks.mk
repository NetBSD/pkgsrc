# $NetBSD: hacks.mk,v 1.2 2008/11/14 16:05:15 tron Exp $

.if !defined(EMACS_HACKS_MK)
EMACS_HACKS_MK=	# defined


###
### Workaround for PR pkg/39778
###
.  include "../../mk/bsd.fast.prefs.mk"
.  if !empty(MACHINE_PLATFORM:MNetBSD-4.99.*-x86_64) || \
      !empty(MACHINE_PLATFORM:MNetBSD-[5-9].*-x86_64)
pre-build:
	${TOUCH} ${WRKSRC}/leim/quail/tsang-b5.el
.  endif

.endif

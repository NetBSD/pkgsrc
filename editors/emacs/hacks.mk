# $NetBSD: hacks.mk,v 1.2.2.1 2009/02/21 23:18:30 tron Exp $

.if !defined(EMACS_HACKS_MK)
EMACS_HACKS_MK=	# defined


###
### Workaround for PR pkg/39778
###
.  include "../../mk/bsd.fast.prefs.mk"
.  if !empty(MACHINE_PLATFORM:MNetBSD-[4-9].*-x86_64)
pre-build:
	${TOUCH} ${WRKSRC}/leim/quail/tsang-b5.el
.  endif

.endif

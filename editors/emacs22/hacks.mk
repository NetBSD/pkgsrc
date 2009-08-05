# $NetBSD: hacks.mk,v 1.1.1.1 2009/08/05 10:30:29 minskim Exp $

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

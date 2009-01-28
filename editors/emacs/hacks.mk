# $NetBSD: hacks.mk,v 1.3 2009/01/28 11:36:34 markd Exp $

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

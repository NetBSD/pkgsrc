# $NetBSD: module.mk,v 1.2 2004/05/11 04:39:03 snj Exp $

.if !defined(PAM_MODULE_MK)
PAM_MODULE_MK=	# defined

.if empty(USE_BUILDLINK3:M[nN][oO])
.  include "../../security/PAM/buildlink3.mk"
.endif

.if defined(DEFAULT_VIEW.pam)
DEFAULT_VIEW.${PKGBASE}=	${DEFAULT_VIEW.pam}
.endif

PAM_MODULEDIR=		${VIEWBASE}/lib/security
PAM_INSTMODULEDIR=	${PREFIX}/${PAM_MODULEDIR:S,${VIEWBASE}/,,}

.endif	# PAM_MODULE_MK

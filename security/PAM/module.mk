# $NetBSD: module.mk,v 1.4 2005/01/14 05:15:39 jlam Exp $

.if !defined(PAM_MODULE_MK)
PAM_MODULE_MK=	# defined

.if empty(USE_BUILDLINK3:M[nN][oO])
.  include "../../mk/pam.buildlink3.mk"
.endif

.if defined(DEFAULT_VIEW.${PAM_TYPE})
DEFAULT_VIEW.${PKGBASE}=	${DEFAULT_VIEW.${PAM_TYPE}}
.endif

PAM_MODULEDIR=		${VIEWBASE}/lib/security
PAM_INSTMODULEDIR=	${PREFIX}/${PAM_MODULEDIR:S,${VIEWBASE}/,,}

.endif	# PAM_MODULE_MK

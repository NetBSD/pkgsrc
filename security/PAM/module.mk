# $NetBSD: module.mk,v 1.5 2005/03/24 22:42:58 jlam Exp $

.if !defined(PAM_MODULE_MK)
PAM_MODULE_MK=	# defined

.include "../../mk/pam.buildlink3.mk"

.if defined(DEFAULT_VIEW.${PAM_TYPE})
DEFAULT_VIEW.${PKGBASE}=	${DEFAULT_VIEW.${PAM_TYPE}}
.endif

PAM_MODULEDIR=		${VIEWBASE}/lib/security
PAM_INSTMODULEDIR=	${PREFIX}/${PAM_MODULEDIR:S,${VIEWBASE}/,,}

.endif	# PAM_MODULE_MK

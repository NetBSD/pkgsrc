# $NetBSD: module.mk,v 1.3 2005/01/14 00:08:46 jlam Exp $

.if !defined(PAM_MODULE_MK)
PAM_MODULE_MK=	# defined

.if empty(USE_BUILDLINK3:M[nN][oO])
.  include "../../security/PAM/buildlink3.mk"
.endif

.if defined(DEFAULT_VIEW.linux-pam)
DEFAULT_VIEW.${PKGBASE}=	${DEFAULT_VIEW.linux-pam}
.endif

PAM_MODULEDIR=		${VIEWBASE}/lib/security
PAM_INSTMODULEDIR=	${PREFIX}/${PAM_MODULEDIR:S,${VIEWBASE}/,,}

.endif	# PAM_MODULE_MK

# $NetBSD: module.mk,v 1.1 2004/01/08 00:08:23 jlam Exp $

.if !defined(PAM_MODULE_MK)
PAM_MODULE_MK=	# defined

.if !defined(NO_BUILDLINK)
.  if empty(USE_BUILDLINK3:M[nN][oO])
.    include "../../security/PAM/buildlink3.mk"
.  elif empty(USE_BUILDLINK2:M[nN][oO])
.    include "../../security/PAM/buildlink2.mk"
.  endif
.endif

.if defined(DEFAULT_VIEW.pam)
DEFAULT_VIEW.${PKGBASE}=	${DEFAULT_VIEW.pam}
.endif

PAM_MODULEDIR=		${VIEWBASE}/lib/security
PAM_INSTMODULEDIR=	${PREFIX}/${PAM_MODULEDIR:S,${VIEWBASE}/,,}

.endif	# PAM_MODULE_MK

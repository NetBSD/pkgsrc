# $NetBSD: builtin.mk,v 1.5 2004/08/06 15:41:46 jlam Exp $

.include "../../mk/bsd.prefs.mk"

_SECURITY_PAM_APPL_H=	/usr/include/security/pam_appl.h

.if !defined(IS_BUILTIN.pam)
IS_BUILTIN.pam=	no
.  if exists(${_SECURITY_PAM_APPL_H}) && \
      empty(_SECURITY_PAM_APPL_H:M${LOCALBASE}/*)
IS_BUILTIN.pam=	yes
.  endif
.endif	# IS_BUILTIN.pam

USE_BUILTIN.pam?=	${IS_BUILTIN.pam}

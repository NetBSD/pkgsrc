# $NetBSD: builtin.mk,v 1.6 2004/08/06 15:43:09 jlam Exp $

.include "../../mk/bsd.prefs.mk"

_SECURITY_PAM_APPL_H=	/usr/include/security/pam_appl.h

.if !defined(IS_BUILTIN.pam)
IS_BUILTIN.pam=	no
.  if empty(_SECURITY_PAM_APPL_H:M${LOCALBASE}/*) && \
      exists(${_SECURITY_PAM_APPL_H})
IS_BUILTIN.pam=	yes
.  endif
.endif	# IS_BUILTIN.pam

USE_BUILTIN.pam?=	${IS_BUILTIN.pam}

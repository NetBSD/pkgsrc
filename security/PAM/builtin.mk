# $NetBSD: builtin.mk,v 1.7 2004/08/12 10:09:49 jlam Exp $

.include "../../mk/bsd.prefs.mk"
_PAM_PAM_APPL_H=	/usr/include/pam/pam_appl.h

_SECURITY_PAM_APPL_H=	/usr/include/security/pam_appl.h

.if !defined(IS_BUILTIN.pam)
IS_BUILTIN.pam=	no
.  if empty(_SECURITY_PAM_APPL_H:M${LOCALBASE}/*) && \
      exists(${_SECURITY_PAM_APPL_H})
IS_BUILTIN.pam=	yes
.  endif
.endif	# IS_BUILTIN.pam

.if !defined(USE_BUILTIN.pam)
USE_BUILTIN.pam?=	${IS_BUILTIN.pam}
.  if empty(_PAM_PAM_APPL_H:M${LOCALBASE}/*) && exists(${_PAM_PAM_APPL_H})
#
# Treat MacOS X's PAM implementation as Linux-PAM-compatible.
#
USE_BUILTIN.pam=	yes
.  endif
.endif

CHECK_BUILTIN.pam?=	no
.if !empty(CHECK_BUILTIN.pam:M[nN][oO])

.if !empty(USE_BUILTIN.pam:M[yY][eE][sS])
BUILDLINK_TRANSFORM.pam+=	-e "s|/include/pam/|/include/security/|"
BUILDLINK_FILES.pam+=		include/pam/*.h
.endif

.endif	# CHECK_BUILTIN.pam

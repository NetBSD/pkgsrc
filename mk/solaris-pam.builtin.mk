# $NetBSD: solaris-pam.builtin.mk,v 1.1 2005/01/14 06:29:55 jlam Exp $

_SECURITY_PAM_APPL_H=	/usr/include/security/pam_appl.h

.if !defined(IS_BUILTIN.solaris-pam)
IS_BUILTIN.solaris-pam=	no
.  if empty(_SECURITY_PAM_APPL_H:M${LOCALBASE}/*) && \
      exists(${_SECURITY_PAM_APPL_H})
IS_BUILTIN.solaris-pam!=	\
	if ${GREP} -q "Copyright.*Sun Microsystems" ${_SECURITY_PAM_APPL_H}; then \
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.  endif
BUILDLINK_VARS+=	IS_BUILTIN.solaris-pam
.endif	# IS_BUILTIN.solaris-pam

USE_BUILTIN.solaris-pam?=	${IS_BUILTIN.solaris-pam}

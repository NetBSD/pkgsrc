# $NetBSD: builtin.mk,v 1.10 2005/01/14 00:08:46 jlam Exp $

.include "../../mk/bsd.prefs.mk"

_PAM_PAM_APPL_H=	/usr/include/pam/pam_appl.h
_SECURITY_PAM_APPL_H=	/usr/include/security/pam_appl.h

.if !defined(IS_BUILTIN.linux-pam)
IS_BUILTIN.linux-pam=	no
.  if empty(_SECURITY_PAM_APPL_H:M${LOCALBASE}/*) && \
      exists(${_SECURITY_PAM_APPL_H})
IS_BUILTIN.linux-pam!=	\
	if ${GREP} -q "The Linux-PAM Framework layer API" ${_SECURITY_PAM_APPL_H}; then \
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.  elif empty(_PAM_PAM_APPL_H:M${LOCALBASE}/*) && exists(${_PAM_PAM_APPL_H})
#
# MacOS X installs their PAM headers as /usr/include/pam/*.h, and their
# PAM implementation is derived from Linux-PAM:
#
#	http://developer.apple.com/documentation/Darwin/Reference/ManPages/man8/pam.8.html
#
IS_BUILTIN.linux-pam=	yes
.  endif
BUILDLINK_VARS+=	IS_BUILTIN.linux-pam
.endif	# IS_BUILTIN.linux-pam

USE_BUILTIN.linux-pam?=	${IS_BUILTIN.linux-pam}

CHECK_BUILTIN.linux-pam?=	no
.if !empty(CHECK_BUILTIN.linux-pam:M[nN][oO])

.  if !empty(USE_BUILTIN.linux-pam:M[yY][eE][sS])
BUILDLINK_TARGETS+=	buildlink-pam-security
.  endif

.  if !target(buildlink-pam-security)
.PHONY: buildlink-pam-security
buildlink-pam-security:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ -d ${BUILDLINK_PREFIX.linux-pam}/include/pam ]; then	\
		${RM} -fr ${BUILDLINK_DIR}/include/security;		\
		${LN} -fs ${BUILDLINK_PREFIX.linux-pam}/include/pam	\
			${BUILDLINK_DIR}/include/security;		\
	fi
.  endif

.endif	# CHECK_BUILTIN.linux-pam

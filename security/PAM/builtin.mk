# $NetBSD: builtin.mk,v 1.11 2005/01/14 07:54:20 jlam Exp $

.include "../../mk/bsd.prefs.mk"

_LINUX_PAM_APPL_HEADERS=	/usr/include/pam/pam_appl.h		\
				/usr/include/security/pam_appl.h
_LINUX_PAM_IDENT=		The Linux-PAM Framework layer API

.if !defined(IS_BUILTIN.linux-pam)
IS_BUILTIN.linux-pam=	no
.  for _inc_ in ${_LINUX_PAM_APPL_HEADERS}
.    if !empty(IS_BUILTIN.linux-pam:M[nN][oO]) && exists(${_inc_})
IS_BUILTIN.linux-pam!=	\
	case ${_inc_} in						\
	${LOCALBASE}/*)							\
		${ECHO} "no";						\
		;;							\
	*)								\
		if ${GREP} -q "${_LINUX_PAM_IDENT}" ${_inc_}; then	\
			${ECHO} "yes";					\
		else							\
			${ECHO} "no";					\
		fi;							\
		;;							\
	esac
.    endif
.  endfor
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

# $NetBSD: solaris-pam.builtin.mk,v 1.2 2005/01/14 07:54:20 jlam Exp $

_SOLARIS_PAM_APPL_HEADERS=	/usr/include/security/pam_appl.h
_SOLARIS_PAM_IDENT=		Copyright.*Sun Microsystems

.if !defined(IS_BUILTIN.solaris-pam)
IS_BUILTIN.solaris-pam=		no
.  for _inc_ in ${_SOLARIS_PAM_APPL_HEADERS}
.    if !empty(IS_BUILTIN.solaris-pam:M[nN][oO]) && exists(${_inc_})
IS_BUILTIN.solaris-pam!=	\
	case ${_inc_} in						\
	${LOCALBASE}/*)							\
		${ECHO} "no";						\
		;;							\
	*)								\
		if ${GREP} -q "${_SOLARIS_PAM_IDENT}" ${_inc_}; then	\
			${ECHO} "yes";					\
		else							\
			${ECHO} "no";					\
		fi;							\
		;;							\
	esac
.    endif
.  endfor
BUILDLINK_VARS+=	IS_BUILTIN.solaris-pam
.endif	# IS_BUILTIN.solaris-pam

USE_BUILTIN.solaris-pam?=	${IS_BUILTIN.solaris-pam}

# $NetBSD: builtin.mk,v 1.2 2005/01/14 07:47:29 jlam Exp $

_SECURITY_OPENPAM_VERSION_H=	/usr/include/security/openpam_version.h

.if !defined(IS_BUILTIN.openpam)
IS_BUILTIN.openpam=	no
.  if empty(_SECURITY_OPENPAM_VERSION_H:M${LOCALBASE}/*) && \
      exists(${_SECURITY_OPENPAM_VERSION_H})
IS_BUILTIN.openpam=	yes
#
# Create an appropriate package name for the built-in software
# distributed with the system.  This package name can be used to check
# against BUILDLINK_DEPENDS.<pkg> to see if we need to install the
# pkgsrc version or if the built-in one is sufficient.
#
_OPENPAM_VERSION!=	${AWK} '/\#define[ 	]*_OPENPAM_VERSION[ 	]/ {print $$3; }' ${_SECURITY_OPENPAM_VERSION_H}
BUILTIN_PKG.openpam=	openpam-${_OPENPAM_VERSION}
BUILDLINK_VARS+=	BUILTIN_PKG.openpam
.  endif
BUILDLINK_VARS+=	IS_BUILTIN.openpam
.endif	# IS_BUILTIN.openpam

.if !defined(USE_BUILTIN.openpam)
USE_BUILTIN.openpam?=	${IS_BUILTIN.openpam}

.  if defined(BUILTIN_PKG.openpam)
USE_BUILTIN.openpam=	yes
.    for _depend_ in ${BUILDLINK_DEPENDS.openpam}
.      if !empty(USE_BUILTIN.openpam:M[yY][eE][sS])
USE_BUILTIN.openpam!=	\
	if ${PKG_ADMIN} pmatch '${_depend_}' ${BUILTIN_PKG.openpam}; then \
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.      endif
.    endfor
.  endif
BUILDLINK_VARS+=	USE_BUILTIN.openpam
.endif	# USE_BUILTIN.openpam

# $NetBSD: builtin.mk,v 1.4 2004/12/05 06:59:21 jlam Exp $

.for _lib_ in dl
.  if !defined(_BLNK_LIB_FOUND.${_lib_})
_BLNK_LIB_FOUND.${_lib_}!=	\
	if ${TEST} "`${ECHO} /usr/lib/lib${_lib_}.*`" != "/usr/lib/lib${_lib_}.*"; then \
		${ECHO} "yes";						\
	elif ${TEST} "`${ECHO} /lib/lib${_lib_}.*`" != "/lib/lib${_lib_}.*"; then \
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
BUILDLINK_VARS+=	_BLNK_LIB_FOUND.${_lib_}
.  endif
.endfor
.undef _lib_

_DL_H=	/usr/include/dlfcn.h

.if !defined(IS_BUILTIN.dlcompat)
IS_BUILTIN.dlcompat=	no
.  if !empty(_BLNK_LIB_FOUND.dl:M[yY][eE][sS]) && exists(${_DL_H})
IS_BUILTIN.dlcompat=	yes
.    if !empty(IS_BUILTIN.dlcompat:M[yY][eE][sS])
_DL_VERSION=		20030629
BUILTIN_PKG.dlcompat=	dlcompat-${_DL_VERSION}
BUILDLINK_VARS+=	BUILTIN_PKG.dlcompat
.    endif
.  endif
BUILDLINK_VARS+=	IS_BUILTIN.dlcompat
.endif	# IS_BUILTIN.dlcompat

.if !defined(USE_BUILTIN.dlcompat)
USE_BUILTIN.dlcompat?=	${IS_BUILTIN.dlcompat}
PREFER.dlcompat?=	pkgsrc

.  if defined(BUILTIN_PKG.dlcompat)
USE_BUILTIN.dlcompat=	yes
.    for _depend_ in ${BUILDLINK_DEPENDS.dlcompat}
.      if !empty(USE_BUILTIN.dlcompat:M[yY][eE][sS])
USE_BUILTIN.dlcompat!=							\
	if ${PKG_ADMIN} pmatch '${_depend_}' ${BUILTIN_PKG.dlcompat}; then \
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.      endif
.    endfor
.  endif

.  if ${PREFER.dlcompat} == "native"
USE_BUILTIN.dlcompat=	yes
.  endif

.  if !empty(IS_BUILTIN.dlcompat:M[nN][oO]) || \
      (${PREFER.dlcompat} == "pkgsrc")
USE_BUILTIN.dlcompat=	no
.  endif
.endif	# USE_BUILTIN.dlcompat

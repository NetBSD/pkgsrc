# $NetBSD: builtin.mk,v 1.1 2004/04/28 03:35:58 jlam Exp $

_SKEY_H=	/usr/include/skey.h

.if !defined(IS_BUILTIN.skey)
IS_BUILTIN.skey=	no
.  if exists(${_SKEY_H})
IS_BUILTIN.skey=	yes
# XXX
# XXX Consider the native skey to be skey-1.1.5.
# XXX
BUILTIN_PKG.skey=	skey-1.1.5
BUILDLINK_VARS+=	BUILTIN_PKG.skey
.  endif
BUILDLINK_VARS+=	IS_BUILTIN.skey
.endif	# IS_BUILTIN.skey

.if !defined(USE_BUILTIN.skey)
USE_BUILTIN.skey?=	${IS_BUILTIN.skey}
PREFER.skey?=		pkgsrc

.  if defined(BUILTIN_PKG.skey)
USE_BUILTIN.skey=	yes
.    for _depend_ in ${BUILDLINK_DEPENDS.skey}
.      if !empty(USE_BUILTIN.skey:M[yY][eE][sS])
USE_BUILTIN.skey!=	\
	if ${PKG_ADMIN} pmatch '${_depend_}' ${BUILTIN_PKG.skey}; then	\
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.      endif
.    endfor
.  endif

.  if ${PREFER.skey} == "native"
.    if (${OPSYS} == "NetBSD") && exists(${_SKEY_H})
USE_BUILTIN.skey=	yes
_INCOMPAT_SKEY?=	# should be set from defs.${OPSYS}.mk
.      for _pattern_ in ${_INCOMPAT_SKEY} ${INCOMPAT_SKEY}
.        if !empty(MACHINE_PLATFORM:M${_pattern_})
USE_BUILTIN.skey=	no
.        endif
.      endfor
.    endif
.  endif

.  if defined(USE_SKEY)
.    if !empty(IS_BUILTIN.skey:M[nN][oO]) && \
        (${PREFER.skey} == "pkgsrc")
USE_BUILTIN.skey=	no
.    endif
.  endif
.endif	# USE_BUILTIN.skey

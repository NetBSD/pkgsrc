# $NetBSD: builtin.mk,v 1.1.1.1 2004/11/05 15:05:30 peter Exp $

_PF_VERSION=	3.6	# pkg default
_PF_PFVAR_H=	/usr/include/net/pfvar.h

.if !defined(IS_BUILTIN.pflkm)
IS_BUILTIN.pflkm=	no
.  if exists(${_PF_PFVAR_H})
IS_BUILTIN.pflkm=	yes

# OpenBSD 3.6: pf_cksum_fixup added
_PF_3_6!=	${GREP} -c pf_cksum_fixup ${_PF_PFVAR_H} || ${TRUE}

.if ${_PF_3_6} == "1"
BUILTIN_PKG.pflkm=	3.6
.else
BUILTIN_PKG.pflkm=	3.5
.endif

_PF_VERSION=		${BUILTIN_PKG.pflkm}

.endif	# exists(${_PF_PFVAR_H})

.if !defined(USE_BUILTIN.pflkm)
USE_BUILTIN.pflkm?=	${IS_BUILTIN.pflkm}

.  if defined(BUILTIN_PKG.pflkm)
USE_BUILTIN.pflkm=	yes
.    for _depend_ in ${BUILDLINK_DEPENDS.pflkm}
.      if !empty(USE_BUILTIN.pflkm:M[yY][eE][sS])
USE_BUILTIN.pflkm!=	\
	if ${PKG_ADMIN} pmatch '${_depend_}' ${BUILTIN_PKG.pflkm}; then \
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.      endif
.    endfor
.  endif
.endif	# USE_BUILTIN.pflkm
.endif  # IS_BUILTIN.pflkm

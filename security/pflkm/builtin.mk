# $NetBSD: builtin.mk,v 1.2 2004/12/01 00:20:20 peter Exp $

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

.  endif	# exists(${_PF_PFVAR_H})
.endif	# IS_BUILTIN.pflkm

USE_BUILTIN.pflkm?=	${IS_BUILTIN.pflkm}

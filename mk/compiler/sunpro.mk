# $NetBSD: sunpro.mk,v 1.1 2004/02/01 00:31:00 jlam Exp $

.if !defined(COMPILER_SUNPRO_MK)
COMPILER_SUNPRO_MK=	defined

.include "../../mk/bsd.prefs.mk"

SUNWSPROBASE?=	/opt/SUNWspro
CC=	${SUNWSPROBASE}/bin/cc
CPP=	${SUNWSPROBASE}/bin/cc -E
CXX=	${SUNWSPROBASE}/bin/CC

_COMPILER_LD_FLAG=	# empty

CC_VERSION!=	${CC} -V 2>&1 | ${GREP} '^cc'

.endif	# COMPILER_SUNPRO_MK

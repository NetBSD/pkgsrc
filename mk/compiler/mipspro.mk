# $NetBSD: mipspro.mk,v 1.3 2004/02/01 01:02:37 jlam Exp $

.if !defined(COMPILER_MIPSPRO_MK)
COMPILER_MIPSPRO_MK=	defined

MIPSPROBASE?=	/usr

CC=	${MIPSPROBASE}/bin/cc
CPP=	${MIPSPROBASE}/bin/cc -E
CXX=	${MIPSPROBASE}/bin/CC

CC_VERSION!=	${CC} -V 2>&1 | ${GREP} '^cc'

.endif	# COMPILER_MIPSPRO_MK

# New ports collection makefile for:	Numeric Python
# Version required:	1.1
# Date created:		18 March 1998
# Whom:			tsarna@endicor.com
#
# $NetBSD: Makefile,v 1.2 1998/04/12 21:54:37 tron Exp $

DISTNAME=	NumPy-11
PKGNAME=	py-Numeric-1.1
CATEGORIES=	math
MASTER_SITES=	ftp://ftp-icf.llnl.gov/pub/python/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@endicor.com

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python
RUN_DEPENDS=	python:${PORTSDIR}/lang/python

WRKSRC=		${WRKDIR}/LLNLDistribution/Numerical
ALL_TARGET=	default

.if ${MACHINE_ARCH} == "powerpc" || ${MACHINE_ARCH} == "mips" || ${MACHINE_ARCH} == "alpha"
IGNORE="Needs dynamic loading"
.endif

post-install:
	(cd ${WRKSRC}/Lib ; \
	python -O ${PREFIX}/lib/python1.5/compileall.py . ; \
	${INSTALL_DATA} *.py *.pyc *.pyo ${PREFIX}/lib/python1.5/site-packages)

.include <bsd.port.mk>

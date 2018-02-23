# $NetBSD: Makefile,v 1.3 2018/02/23 06:34:08 adam Exp $

DISTNAME=	crcmod-1.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/crcmod/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://crcmod.sourceforge.net/
COMMENT=	Cyclic Redundancy Checksums in Python
LICENSE=	mit

do-test:
	${SETENV} PYTHONPATH=${WRKSRC} ${PYTHONBIN} -m test

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"

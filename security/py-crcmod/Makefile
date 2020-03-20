# $NetBSD: Makefile,v 1.4 2020/03/20 11:58:18 nia Exp $

DISTNAME=	crcmod-1.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/crcmod/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	http://crcmod.sourceforge.net/
COMMENT=	Cyclic Redundancy Checksums in Python
LICENSE=	mit

do-test:
	${SETENV} PYTHONPATH=${WRKSRC} ${PYTHONBIN} -m test

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"

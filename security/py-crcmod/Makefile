# $NetBSD: Makefile,v 1.1 2018/01/30 19:07:48 bsiegert Exp $

DISTNAME=	crcmod-1.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	${MASYER_SITE_PYPI:=c/crcmod/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://crcmod.sourceforge.net/
COMMENT=	Cyclic Redundancy Checksums in Python
LICENSE=	mit

do-test:
	env PYTHONPATH=${WRKSRC} ${PYTHONBIN} -m test

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"

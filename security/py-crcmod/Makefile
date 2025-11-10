# $NetBSD: Makefile,v 1.6 2025/11/10 19:16:36 bsiegert Exp $

DISTNAME=	crcmod-1.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/crcmod/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://crcmod.sourceforge.net/
COMMENT=	Cyclic Redundancy Checksums in Python
LICENSE=	mit

do-test:
	${SETENV} PYTHONPATH=${WRKSRC} ${PYTHONBIN} -m test

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

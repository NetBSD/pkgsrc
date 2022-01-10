# $NetBSD: Makefile,v 1.5 2022/01/10 09:00:02 wiz Exp $

DISTNAME=	crcmod-1.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/crcmod/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	http://crcmod.sourceforge.net/
COMMENT=	Cyclic Redundancy Checksums in Python
LICENSE=	mit

do-test:
	${SETENV} PYTHONPATH=${WRKSRC} ${PYTHONBIN} -m test

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

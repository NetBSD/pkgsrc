# $NetBSD: Makefile,v 1.4 2022/01/14 17:52:03 wiz Exp $

DISTNAME=	simplesha3-2015.09.22.post1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/simplesha3/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.dlitz.net/software/pycrypto/
COMMENT=	Simple SHA-3 implementation for Python
LICENSE=	public-domain

.include "../../lang/python/pyversion.mk"

.if ${PYPKGPREFIX} != "py27"
EGG_NAME=	simplesha3-2015.9.22.post1
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

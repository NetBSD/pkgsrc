# $NetBSD: Makefile,v 1.13 2026/05/20 08:01:09 adam Exp $

DISTNAME=	bitstring-4.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bitstring/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/scott-griffiths/bitstring
COMMENT=	Simple construction, analysis and modification of binary data
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-bitarray>=3.0.0:../../devel/py-bitarray
DEPENDS+=	${PYPKGPREFIX}-tibs>=0.5.6:../../misc/py-tibs

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"

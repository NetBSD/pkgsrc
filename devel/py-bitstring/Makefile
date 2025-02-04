# $NetBSD: Makefile,v 1.11 2025/02/04 06:35:41 adam Exp $

DISTNAME=	bitstring-4.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bitstring/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/scott-griffiths/bitstring
COMMENT=	Simple construction, analysis and modification of binary data
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-bitarray>=3.0.0:../../devel/py-bitarray

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"

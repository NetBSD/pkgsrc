# $NetBSD: Makefile,v 1.10 2024/11/11 07:28:02 wiz Exp $

DISTNAME=	bitstring-4.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bitstring/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/scott-griffiths/bitstring
COMMENT=	Simple construction, analysis and modification of binary data
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-bitarray>=2.9.0:../../devel/py-bitarray

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"

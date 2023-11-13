# $NetBSD: Makefile,v 1.4 2023/11/13 10:59:21 wiz Exp $

DISTNAME=	bitstring-4.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bitstring/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/scott-griffiths/bitstring
COMMENT=	Simple construction, analysis and modification of binary data
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-bitarray>=2.8.0:../../devel/py-bitarray

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

# remove broken test so others can run
# https://github.com/scott-griffiths/bitstring/issues/301
pre-test:
	${RM} ${WRKSRC}/bitstring/plugin_test.py

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"

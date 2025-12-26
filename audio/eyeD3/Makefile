# $NetBSD: Makefile,v 1.25 2025/12/26 12:42:32 adam Exp $

DISTNAME=	eyed3-0.9.9
PKGNAME=	${DISTNAME:S/d3/D3/}
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/eyed3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://eyed3.readthedocs.io/
COMMENT=	Python audio data toolkit (ID3 and MP3)
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-deprecation>=2.1.0:../../devel/py-deprecation
DEPENDS+=	${PYPKGPREFIX}-filetype>=1.2.0:../../sysutils/py-filetype
TEST_DEPENDS+=	${PYPKGPREFIX}-factory_boy>=3.3.3:../../devel/py-factory_boy
TEST_DEPENDS+=	${PYPKGPREFIX}-flake8>=7.2.0:../../devel/py-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=6.1.1:../../devel/py-test-cov

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"

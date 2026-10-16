# $NetBSD: Makefile,v 1.19 2026/10/16 19:09:15 adam Exp $

DISTNAME=	jedi-0.20.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	editors python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jedi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/davidhalter/jedi
COMMENT=	Autocompletion tool for Python that can be used for text editors
LICENSE=	mit

EXTRACT_USING=	bsdtar

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-parso>=0.8.4:../../lang/py-parso
TEST_DEPENDS+=	${PYPKGPREFIX}-attrs>=0:../../devel/py-attrs
TEST_DEPENDS+=	${PYPKGPREFIX}-colorama>=0:../../comms/py-colorama
TEST_DEPENDS+=	${PYPKGPREFIX}-docopt>=0:../../devel/py-docopt

USE_LANGUAGES=	# none

# as of 0.20.0
# 6 failed, 3874 passed, 107 skipped, 5 xfailed

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"

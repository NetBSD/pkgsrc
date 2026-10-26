# $NetBSD: Makefile,v 1.17 2026/10/26 05:29:27 adam Exp $

DISTNAME=	inflect-7.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/inflect/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jazzband/inflect
COMMENT=	Correctly generate plurals, ordinals, indefinite articles for English
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=7.0.0:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-jaraco.functools>=0:../../devel/py-jaraco.functools
DEPENDS+=	${PYPKGPREFIX}-more-itertools>=8.5.0:../../devel/py-more-itertools
DEPENDS+=	${PYPKGPREFIX}-typeguard>=4.0.1:../../devel/py-typeguard
TEST_DEPENDS+=	${PYPKGPREFIX}-pygments>=0:../../textproc/py-pygments
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"

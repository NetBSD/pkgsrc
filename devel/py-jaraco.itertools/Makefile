# $NetBSD: Makefile,v 1.11 2025/06/03 17:56:20 adam Exp $

DISTNAME=	jaraco_itertools-6.4.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/./}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jaraco.itertools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaraco/jaraco.itertools
COMMENT=	Additional itertools in the spirit of stdlib's itertools
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=1.15.0:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-inflect-[0-9]*:../../lang/py-inflect
DEPENDS+=	${PYPKGPREFIX}-more-itertools>=4.0.0:../../devel/py-more-itertools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"

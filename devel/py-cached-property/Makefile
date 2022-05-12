# $NetBSD: Makefile,v 1.14 2022/05/12 08:20:36 wiz Exp $

DISTNAME=	cached-property-1.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cached-property/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pydanny/cached-property
COMMENT=	Decorator for caching properties in classes
LICENSE=	modified-bsd

.include "../../lang/python/pyversion.mk"

.if ${_PYTHON_VERSION} != 27
# freezegun is only available for python 3
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun-[0-9]*:../../devel/py-freezegun
.endif

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

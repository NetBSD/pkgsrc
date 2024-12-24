# $NetBSD: Makefile,v 1.30 2024/12/24 11:57:05 adam Exp $

DISTNAME=	hatchling-1.27.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hatchling/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hatch.pypa.io/
COMMENT=	Modern, extensible Python build backend
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-packaging>=24.2:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pathspec>=0.10.1:../../devel/py-pathspec
DEPENDS+=	${PYPKGPREFIX}-pluggy>=1.0.0:../../devel/py-pluggy
DEPENDS+=	${PYPKGPREFIX}-trove-classifiers-[0-9]*:../../misc/py-trove-classifiers

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=1.2.2:../../textproc/py-tomli
.endif

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} hatchling hatchling-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"

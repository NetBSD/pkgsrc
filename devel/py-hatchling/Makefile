# $NetBSD: Makefile,v 1.9 2023/03/29 09:34:07 wiz Exp $

DISTNAME=	hatchling-1.13.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hatchling/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hatch.pypa.io/
COMMENT=	Modern, extensible Python build backend
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-editables>=0.3:../../devel/py-editables
DEPENDS+=	${PYPKGPREFIX}-packaging>=21.3:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pathspec>=0.10.1:../../devel/py-pathspec
DEPENDS+=	${PYPKGPREFIX}-pluggy>=1.0.0:../../devel/py-pluggy

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=1.2.2:../../textproc/py-tomli
.endif

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} hatchling hatchling-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"

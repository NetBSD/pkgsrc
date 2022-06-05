# $NetBSD: Makefile,v 1.3 2022/06/05 02:56:20 mef Exp $

DISTNAME=	hatchling-1.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hatchling/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hatch.pypa.io/
COMMENT=	Modern, extensible Python build backend
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-pathspec>0:../../devel/py-pathspec
DEPENDS+=	${PYPKGPREFIX}-pluggy-[0-9]*:../../devel/py-pluggy

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} hatchling hatchling-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"

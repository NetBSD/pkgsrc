# $NetBSD: Makefile,v 1.1 2025/10/12 17:48:51 wiz Exp $

DISTNAME=	poetry_dynamic_versioning-1.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/poetry-dynamic-versioning/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mtkennerly/poetry-dynamic-versioning
COMMENT=	Plugin for Poetry to enable dynamic versioning based on VCS tags
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.0:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-dunamai>=1.25.0:../../devel/py-dunamai
DEPENDS+=	${PYPKGPREFIX}-tomlkit>=0.4:../../textproc/py-tomlkit
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.11.1:../../textproc/py-jinja2
TEST_DEPENDS+=	${PYPKGPREFIX}-poetry>=1.2:../../devel/py-poetry

# as of 1.9.1
# 8 failed, 18 passed, 3 skipped, 18 errors

.if make(test)
ALLOW_NETWORK_ACCESS=	yes
.endif

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} poetry-dynamic-versioning poetry-dynamic-versioning-${PYVERSSUFFIX} || ${TRUE}

pre-test:
	${LN} -sf ${PREFIX}/bin/poetry-${PYVERSSUFFIX} ${BUILDLINK_DIR}/bin/poetry

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"

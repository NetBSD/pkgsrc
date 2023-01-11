# $NetBSD: Makefile,v 1.1 2023/01/11 17:47:48 nikita Exp $

DISTNAME=	gitlint-0.18.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=jorisroovers/}
GITHUB_PROJECT=	gitlint
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jorisroovers/gitlint/
COMMENT=	Git commit message linter
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-click-[0-9]*:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-sh-[0-9]*:../../sysutils/py-sh
DEPENDS+=	${PYPKGPREFIX}-arrow-[0-9]*:../../time/py-arrow

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	git-[0-9]*:../../devel/git

USE_LANGUAGES=	# none

WRKSRC=		${WRKDIR}/${DISTNAME}/gitlint-core

PYTHON_VERSIONS_INCOMPATIBLE=	27

FILES_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
# TODO: fix the EGG_INFODIR divergenging name.

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} gitlint gitlint-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/alternatives.mk"
.include "../../mk/bsd.pkg.mk"

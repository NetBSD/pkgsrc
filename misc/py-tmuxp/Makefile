# $NetBSD: Makefile,v 1.3 2026/05/04 06:22:48 wiz Exp $

DISTNAME=	tmuxp-${VERSION}
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_GITHUB:=tmux-python/}
GITHUB_PROJECT=	tmuxp
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tmuxp.git-pull.com/
COMMENT=	Session manager for tmux
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-libtmux>=0.55:../../misc/py-libtmux
DEPENDS+=	${PYPKGPREFIX}-yaml>=6:../../textproc/py-yaml

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.29:../../devel/py-hatchling

# codecov
# coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=7:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-rerunfailures>=0:../../devel/py-test-rerunfailures
TEST_DEPENDS+=	${PYPKGPREFIX}-docutils>=0:../../textproc/py-docutils
TEST_DEPENDS+=	${PYPKGPREFIX}-sphinx>=0:../../textproc/py-sphinx

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} tmuxp tmuxp-${PYVERSSUFFIX} || \
	${TRUE}

.include "version.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"

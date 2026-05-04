# $NetBSD: Makefile,v 1.2 2026/05/04 06:10:04 kim Exp $

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
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

# codecov
# coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=7:../../devel/py-test-cov

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} tmuxp tmuxp-${PYVERSSUFFIX} || \
	${TRUE}

.include "version.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"

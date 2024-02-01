# $NetBSD: Makefile,v 1.13 2024/02/01 08:45:03 wiz Exp $

DISTNAME=	unknown-horizons-2019.1
PKGREVISION=	5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=unknown-horizons/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://unknown-horizons.org/
COMMENT=	2D RTS game with an emphasis on economy and city building
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	intltool msgfmt

DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
DEPENDS+=	fifengine-[0-9]*:../../devel/fifengine

EGG_NAME=	UnknownHorizons-${PKGVERSION_NOREV}

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-yaml

REPLACE_PYTHON+=	run_server.py
REPLACE_PYTHON+=	run_uh.py

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Setting paths.
SUBST_FILES.paths+=	run_uh.py setup.py
SUBST_VARS.paths+=	PREFIX PKGMANDIR

# Misses generating these files sometimes somehow
post-build:
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ${PYTHONBIN} horizons/engine/generate_atlases.py 2048

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

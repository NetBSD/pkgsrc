# $NetBSD: Makefile,v 1.6 2022/01/09 18:51:21 wiz Exp $

DISTNAME=	unknown-horizons-2019.1
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=unknown-horizons/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://unknown-horizons.org/
COMMENT=	2D RTS game with an emphasis on economy and city building
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	intltool msgfmt

DEPENDS+=	${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
DEPENDS+=	fifengine-[0-9]*:../../devel/fifengine

PYTHON_VERSIONED_DEPENDENCIES=	Pillow

EGG_NAME=	UnknownHorizons-${PKGVERSION_NOREV}

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

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"

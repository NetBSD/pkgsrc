# $NetBSD: Makefile,v 1.2 2019/08/07 12:15:06 nia Exp $

DISTNAME=	unknown-horizons-2019.1
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
DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
DEPENDS+=	fifengine-[0-9]*:../../devel/fifengine

REPLACE_PYTHON+=	run_server.py
REPLACE_PYTHON+=	run_uh.py

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Setting paths.
SUBST_FILES.paths+=	run_uh.py setup.py
SUBST_VARS.paths+=	PREFIX PKGMANDIR

# Misses generating these files sometimes somehow
post-build:
	cd ${WRKSRC} && ${PYTHONBIN} horizons/engine/generate_atlases.py 2048

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"

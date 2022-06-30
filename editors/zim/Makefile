# $NetBSD: Makefile,v 1.49 2022/06/30 11:18:21 nia Exp $

DISTNAME=	zim-0.74.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://zim-wiki.org/downloads/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://zim-wiki.org/
COMMENT=	Zim brings the concept of a wiki to your desktop
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3
DEPENDS+=	${PYPKGPREFIX}-xdg-[0-9]*:../../devel/py-xdg
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-cElementTree-[0-9]*:../../textproc/py-cElementTree
DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils

USE_LANGUAGES=	# none

BUILD_DEFS=	PKG_SYSCONFBASE

REPLACE_PYTHON=	zim.py

PYTHON_VERSIONS_INCOMPATIBLE=	27

SUBST_CLASSES+=			data-path
SUBST_STAGE.data-path=		pre-configure
SUBST_FILES.data-path=		zim/config/basedirs.py
SUBST_SED.data-path=		-e 's,/usr/share/,${PREFIX}/share/,'
SUBST_SED.data-path+=		-e 's,/etc/xdg/,${PKG_SYSCONFBASE}/xdg/,'

SUBST_CLASSES+=			man-path
SUBST_STAGE.man-path=		pre-configure
SUBST_FILES.man-path+=		setup.py
SUBST_SED.man-path=		-e s,share/man/man1,${PKGMANDIR}/man1,

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"

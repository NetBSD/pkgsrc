# $NetBSD: Makefile,v 1.15 2010/12/07 14:09:55 wiz Exp $

DISTNAME=	kdegames-${_KDE_VERSION}
CATEGORIES=	games
COMMENT=	Games for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1

REPLACE_PERL+=	katomic/katomic-levelset-upd.pl

DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted 

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../games/ggz-client-libs/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/qca2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/kdebase-runtime4/buildlink3.mk"
.include "../../x11/kdebindings4-python/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

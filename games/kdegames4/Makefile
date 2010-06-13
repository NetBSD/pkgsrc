# $NetBSD: Makefile,v 1.7 2010/06/13 22:44:21 wiz Exp $

DISTNAME=	kdegames-${_KDE_VERSION}
PKGREVISION=	1
CATEGORIES=	games
COMMENT=	Games for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1

REPLACE_PERL+=	katomic/katomic-levelset-upd.pl

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../games/ggz-client-libs/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/qca2/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/kdebase-runtime4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.2 2009/10/11 08:13:38 markd Exp $

DISTNAME=	kdegames-${_KDE_VERSION}
CATEGORIES=	games
COMMENT=	Games for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../games/ggz-client-libs/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/qca2/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/kdebase-runtime4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

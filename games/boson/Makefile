# $NetBSD: Makefile,v 1.27 2007/11/30 21:55:06 wiz Exp $
#

DISTNAME=		boson-all-0.8
PKGNAME=		${DISTNAME:S/-all//}
PKGREVISION=		16
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=boson/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://boson.eu.org/
COMMENT=		OpenGL real-time strategy game for KDE 3

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake msgfmt
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--disable-debug

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../games/kdegames3/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/lib3ds/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.20 2005/07/25 12:49:08 markd Exp $
#

DISTNAME=	kmplayer-0.9.0a
CATEGORIES=	multimedia kde
MASTER_SITES=	http://www.xs4all.nl/~jjvrieze/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://www.xs4all.nl/~jjvrieze/
COMMENT=	KDE frontend to mplayer

BUILD_USES_MSGFMT=	yes
DEPENDS=		mplayer>=1.0rc3:../../multimedia/mplayer
DEPENDS+=		mencoder>=1.0rc3:../../multimedia/mencoder
DEPENDS+=		xine-arts>=1rc0a:../../audio/xine-arts

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake perl
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--without-gstreamer

SHLIBTOOL_OVERRIDE=	libtool

SUBST_CLASSES+=		desktop
SUBST_MESSAGE.desktop=	"Fixing application launcher."
SUBST_STAGE.desktop=	pre-configure
SUBST_FILES.desktop=	src/kmplayer.desktop
SUBST_SED.desktop=	-e 's|@PREFIX@|${PREFIX}|g'

.include "../../devel/pkg-config/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.16 2005/04/11 21:46:41 tv Exp $
#

DISTNAME=	kmplayer-0.8.4b
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
USE_GNU_TOOLS+=		make
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PERL5=		build

CONFIGURE_ARGS+=	--without-gstreamer

SHLIBTOOL_OVERRIDE=	libtool

SUBST_CLASSES+=		desktop
SUBST_MESSAGE.desktop=	"Fixing application launcher."
SUBST_STAGE.desktop=	pre-configure
SUBST_FILES.desktop=	src/kmplayer.desktop
SUBST_SED.desktop=	-e 's|@PREFIX@|${PREFIX}|g'

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

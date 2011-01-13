# $NetBSD: Makefile,v 1.19 2011/01/13 13:37:03 wiz Exp $

DISTNAME=	hydrogen-0.8.0
PKGREVISION=	10
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hydrogen/}

MAINTAINER=	chris.wareham@btinternet.com
HOMEPAGE=	http://www.hydrogen-music.org/
COMMENT=	Real time drum machine/sequencer

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--disable-alsa-seq
CONFIGURE_ARGS+=	--disable-jack-support

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} != "native" || exists(${X11BASE}/include/X11/extensions/Xinerama.h)
.include "../../x11/libXinerama/buildlink3.mk"
CONFIGURE_ARGS+=	--with-xinerama
.endif

.include "../../audio/libhydrogen/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.13 2007/06/15 17:04:17 joerg Exp $

DISTNAME=	hydrogen-0.8.0
PKGREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hydrogen/}

MAINTAINER=	chris.wareham@btinternet.com
HOMEPAGE=	http://hydrogen.sourceforge.net/
COMMENT=	Real time drum machine/sequencer

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

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../audio/libhydrogen/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

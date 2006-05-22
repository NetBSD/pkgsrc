# $NetBSD: Makefile,v 1.11 2006/05/22 22:44:44 wiz Exp $

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

.if exists(${X11BASE}/include/X11/extensions/Xinerama.h)
CONFIGURE_ARGS+=	--with-xinerama
.endif

.include "../../audio/libhydrogen/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

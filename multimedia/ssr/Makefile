# $NetBSD: Makefile,v 1.1 2016/02/08 01:17:53 markd Exp $
#

DISTNAME=	ssr-0.3.6
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=MaartenBaert/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.maartenbaert.be/simplescreenrecorder/
COMMENT=	Screen recorder for Linux
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Linux"
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--enable-oss=yes
LDFLAGS+=	${LIBOSSAUDIO}
.endif

.include "../../audio/jack/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../multimedia/ffmpeg2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

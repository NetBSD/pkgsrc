# $NetBSD: Makefile,v 1.4 2016/08/04 17:03:37 ryoon Exp $
#

DISTNAME=	ssr-0.3.6
PKGREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=MaartenBaert/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.maartenbaert.be/simplescreenrecorder/
COMMENT=	Screen recorder for Linux
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake bash:run
USE_LANGUAGES=	c c++

REPLACE_BASH=	scripts/ssr-glinject

CFLAGS.NetBSD+=	-DBSD

.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}

.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../audio/jack/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../multimedia/ffmpeg2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

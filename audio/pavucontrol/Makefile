# $NetBSD: Makefile,v 1.58 2018/08/22 09:42:57 wiz Exp $
#

DISTNAME=	pavucontrol-3.0
PKGREVISION=	13
CATEGORIES=	audio
MASTER_SITES=	http://freedesktop.org/software/pulseaudio/pavucontrol/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://freedesktop.org/software/pulseaudio/pavucontrol/
COMMENT=	Volume control tool ("mixer") for the PulseAudio sound server
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++11
USE_TOOLS+=	pkg-config gmake intltool perl msgfmt

CONFIGURE_ARGS+=	--disable-lynx

.include "../../audio/libcanberra/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/gtkmm3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

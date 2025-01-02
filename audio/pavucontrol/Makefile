# $NetBSD: Makefile,v 1.105 2025/01/02 13:51:21 ryoon Exp $
#

DISTNAME=	pavucontrol-6.1
CATEGORIES=	audio
MASTER_SITES=	http://freedesktop.org/software/pulseaudio/pavucontrol/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://freedesktop.org/software/pulseaudio/pavucontrol/
COMMENT=	Volume control tool ("mixer") for the PulseAudio sound server
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++11
USE_TOOLS+=	pkg-config gmake intltool perl msgfmt

MESON_ARGS+=	-Dlynx=false

.include "../../audio/libcanberra/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../x11/gtkmm4/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../mk/bsd.pkg.mk"

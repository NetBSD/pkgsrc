# $NetBSD: Makefile,v 1.59 2018/11/14 22:21:04 kleink Exp $
#

DISTNAME=	paprefs-0.9.10
PKGREVISION=	29
CATEGORIES=	audio
MASTER_SITES=	http://freedesktop.org/software/pulseaudio/paprefs/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://freedesktop.org/software/pulseaudio/paprefs/
COMMENT=	Configuration dialog for the PulseAudio sound server
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++11
USE_TOOLS+=	pkg-config gmake intltool perl msgfmt

CONFIGURE_ARGS+=	--disable-lynx

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gconfmm/buildlink3.mk"
.include "../../devel/libglademm/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

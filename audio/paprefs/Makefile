# $NetBSD: Makefile,v 1.33 2013/11/25 12:00:46 wiz Exp $
#

DISTNAME=	paprefs-0.9.10
PKGREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	http://0pointer.de/lennart/projects/paprefs/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://0pointer.de/lennart/projects/paprefs/
COMMENT=	Configuration dialog for the PulseAudio sound server

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
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

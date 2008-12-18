# $NetBSD: Makefile,v 1.1.1.1 2008/12/18 17:50:30 jmcneill Exp $
#

DISTNAME=	pavucontrol-0.9.7
CATEGORIES=	audio
MASTER_SITES=	http://0pointer.de/lennart/projects/pavucontrol/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://0pointer.de/lennart/projects/pavucontrol/
COMMENT=	Volume control tool ("mixer") for the PulseAudio sound server

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config gmake intltool perl
USE_DIRS+=	gnome2-1.5

CONFIGURE_ARGS+=	--disable-lynx

.include "../../audio/libcanberra/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gconfmm/buildlink3.mk"
.include "../../devel/libglademm/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

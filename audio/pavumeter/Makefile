# $NetBSD: Makefile,v 1.43 2016/07/09 06:37:50 wiz Exp $
#

DISTNAME=	pavumeter-0.9.3
PKGREVISION=	37
CATEGORIES=	audio
MASTER_SITES=	http://0pointer.de/lennart/projects/pavumeter/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://0pointer.de/lennart/projects/pavumeter/
COMMENT=	Volume meter for the PulseAudio sound server
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config gmake intltool perl

CONFIGURE_ARGS+=	--disable-lynx

CXXFLAGS+=		-std=c++11

.include "../../audio/libcanberra/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gconfmm/buildlink3.mk"
.include "../../devel/libglademm/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.61 2019/08/11 13:17:57 wiz Exp $
#

DISTNAME=	pavumeter-0.9.3
PKGREVISION=	54
CATEGORIES=	audio
MASTER_SITES=	http://0pointer.de/lennart/projects/pavumeter/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://0pointer.de/lennart/projects/pavumeter/
COMMENT=	Volume meter for the PulseAudio sound server
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++11
USE_TOOLS+=	pkg-config gmake intltool perl

CONFIGURE_ARGS+=	--disable-lynx

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

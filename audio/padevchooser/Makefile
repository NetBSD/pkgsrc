# $NetBSD: Makefile,v 1.3 2009/07/22 09:01:18 wiz Exp $
#

DISTNAME=	padevchooser-0.9.3
CATEGORIES=	audio
MASTER_SITES=	http://0pointer.de/lennart/projects/padevchooser/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://0pointer.de/lennart/projects/padevchooser/
COMMENT=	Tray area icon for the PulseAudio sound server

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS=	pkg-config gmake
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--disable-lynx

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

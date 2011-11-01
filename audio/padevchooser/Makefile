# $NetBSD: Makefile,v 1.13 2011/11/01 06:00:39 sbd Exp $
#

DISTNAME=	padevchooser-0.9.3
PKGREVISION=	8
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

# XXX this test doesnt work properly
#
#pkgbase:=	pulseaudio
#.include "../../mk/pkg-build-options.mk"
#.if empty(PKG_BUILD_OPTIONS.pulseaudio)
#PKG_FAIL_REASON=	"Require pulseaudio with ZeroConf support (avahi)"
#.endif

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.36 2015/11/03 19:10:07 joerg Exp $
#

DISTNAME=	paman-0.9.4
PKGREVISION=	31
CATEGORIES=	audio
MASTER_SITES=	http://0pointer.de/lennart/projects/paman/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://0pointer.de/lennart/projects/paman/
COMMENT=	GTK frontend for the PulseAudio sound server

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c++

CONFIGURE_ARGS+=	--disable-lynx

CXXFLAGS+=		-std=c++11

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../devel/glibmm/buildlink3.mk"
.include "../../devel/libglademm/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"

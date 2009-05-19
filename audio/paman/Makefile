# $NetBSD: Makefile,v 1.2 2009/05/19 07:04:44 abs Exp $
#

DISTNAME=	paman-0.9.4
CATEGORIES=	audio
MASTER_SITES=	http://0pointer.de/lennart/projects/paman/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://0pointer.de/lennart/projects/paman/
COMMENT=	GTK frontend for the PulseAudio sound server

PKG_DESTDIR_SUPPORT=   user-destdir

GNU_CONFIGURE=	yes
USE_DIRS=	gnome2-1.5
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c++

CONFIGURE_ARGS+=	--disable-lynx

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../devel/glibmm/buildlink3.mk"
.include "../../devel/libglademm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

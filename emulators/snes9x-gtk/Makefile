# $NetBSD: Makefile,v 1.1.1.1 2009/01/03 18:46:27 wiz Exp $
#

DISTNAME=	snes9x-1.51-src-gtk-61
PKGNAME=	snes9x-gtk-1.51.61
CATEGORIES=	emulators
MASTER_SITES=	http://bearoso.googlepages.com/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.snes9x.com/phpbb2/viewtopic.php?p=22874
COMMENT=	SNES emulator with GTK frontend

WRKSRC=		${WRKDIR}/snes9x-1.51-src/gtk
GNU_CONFIGURE=	yes
USE_DIRS=	xdg-1.4
USE_LANGUAGES=	c c++
USE_TOOLS+=	intltool pkg-config

CONFIGURE_ARGS+=	--without-opengl

.include "../../audio/portaudio-devel/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/gtkglext/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

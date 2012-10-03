# $NetBSD: Makefile,v 1.23.2.1 2012/10/03 12:07:39 spz Exp $
#

DISTNAME=	snes9x-1.53-src
PKGNAME=	snes9x-gtk-1.53.81
PKGREVISION=	7
CATEGORIES=	emulators
MASTER_SITES=	http://snes9x-gtk.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.snes9x.com/phpbb2/viewtopic.php?p=22874
COMMENT=	SNES emulator with GTK frontend

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${DISTNAME}/gtk
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	intltool pkg-config msgfmt

CONFIGURE_ARGS+=	--without-opengl

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386"
BUILD_DEPENDS+=		nasm>=0.98:../../devel/nasm
.endif

.include "../../audio/portaudio-devel/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/gtkglext/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.10.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

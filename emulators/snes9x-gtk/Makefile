# $NetBSD: Makefile,v 1.59 2018/08/22 09:45:05 wiz Exp $

DISTNAME=	snes9x-1.53-src
PKGNAME=	snes9x-gtk-1.53.81
PKGREVISION=	38
CATEGORIES=	emulators
MASTER_SITES=	http://snes9x-gtk.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.snes9x.com/phpbb3/viewtopic.php?p=22874
COMMENT=	SNES emulator with GTK frontend
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/${DISTNAME}/gtk
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++03
USE_TOOLS+=	intltool msgfmt msgmerge perl pkg-config xgettext

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "options.mk"

.if ${MACHINE_ARCH} == "i386"
BUILD_DEPENDS+=		nasm>=0.98:../../devel/nasm
.endif

.include "../../audio/portaudio-devel/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/gtkglext/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.10.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

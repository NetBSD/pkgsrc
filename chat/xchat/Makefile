# $NetBSD: Makefile,v 1.35 2006/01/24 07:31:58 wiz Exp $

MAINTAINER=		tron@NetBSD.org

.include "Makefile.common"

PKGREVISION=		2

PATCH_SITES=           	${MASTER_SITES}/patches/
PATCHFILES=		xc245-fix-te-notify.diff
PATCH_DIST_STRIP=	-p1

COMMENT=	X11 (X Window System) IRC client, using the GTK2 toolkit

BUILD_USES_MSGFMT=	YES

CONFLICTS=		xchat-gnome-[0-9]*

USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	YES

CONFIGURE_ARGS+=	--enable-textfe
CONFIGURE_ARGS+=	--enable-tcl=no
CONFIGURE_ARGS+=	--disable-perl
CONFIGURE_ARGS+=	--disable-python

LDFLAGS.IRIX+=		-lX11
LDFLAGS.Darwin+=	-lX11

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/xchat/plugins

.include "../../mk/bsd.pkg.mk"

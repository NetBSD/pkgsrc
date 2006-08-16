# $NetBSD: Makefile,v 1.42 2006/08/16 21:25:35 tron Exp $

.include "Makefile.common"

MAINTAINER=		tron@NetBSD.org

PATCH_SITES=		${MASTER_SITES}/patches/
PATCHFILES=		xc266-fix-fi.diff
PATCH_DIST_STRIP=	-p1

COMMENT=	X11 (X Window System) IRC client, using the GTK2 toolkit

CONFLICTS=		xchat-gnome-[0-9]*

USE_TOOLS+=		msgfmt
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

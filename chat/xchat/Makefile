# $NetBSD: Makefile,v 1.45 2007/01/16 11:07:59 tron Exp $

.include "Makefile.common"

MAINTAINER=		tron@NetBSD.org

COMMENT=	X11 (X Window System) IRC client, using the GTK2 toolkit

CONFLICTS=		xchat-gnome-[0-9]*

USE_TOOLS+=		msgfmt
USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	YES

CONFIGURE_ARGS+=	--enable-tcl=no
CONFIGURE_ARGS+=	--disable-perl
CONFIGURE_ARGS+=	--disable-python

LDFLAGS.IRIX+=		-lX11

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.if ${OPSYS} == "Darwin"
INSTALL_UNSTRIPPED=	YES

.if empty(PKG_BUILD_OPTIONS.gtk2+:Mquartz)
LDFLAGS.Darwin+=	-lX11
.else
CONFIGURE_ARGS+=	--disable-xlib
.endif
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/xchat/plugins

.include "../../mk/bsd.pkg.mk"

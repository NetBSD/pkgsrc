# $NetBSD: Makefile,v 1.38 2006/03/14 19:06:19 tron Exp $

.include "Makefile.common"

MAINTAINER=		tron@NetBSD.org

COMMENT=	X11 (X Window System) IRC client, using the GTK2 toolkit

BUILD_USES_MSGFMT=	YES

CONFLICTS=		xchat-gnome-[0-9]*

USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	YES

# The text frontend doesn't compile in X-Chat 2.6.1
#CONFIGURE_ARGS+=	--enable-textfe
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

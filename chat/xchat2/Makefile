# $NetBSD: Makefile,v 1.39 2004/10/30 18:22:35 minskim Exp $
#

.include "Makefile.common"

PKGREVISION=	1

COMMENT=	X11 (X Window System) IRC client, using the GTK2 toolkit

BUILD_USES_MSGFMT=	YES

CONFLICTS=		xchat-gnome-[0-9]*

USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	YES
USE_X11=		YES

CONFIGURE_ARGS+=	--enable-textfe
CONFIGURE_ARGS+=	--enable-tcl=no
CONFIGURE_ARGS+=	--disable-perl
CONFIGURE_ARGS+=	--disable-python

LDFLAGS.IRIX+=		-lX11
LDFLAGS.Darwin+=	-lX11

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=            USE_INET6 USE_SOCKS XCHAT_USE_SSL

# IPv6 support
.if defined(USE_INET6) && !empty(USE_INET6:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=        --enable-ipv6
.endif

# Socks support
.if defined(USE_SOCKS) && !empty(USE_SOCKS:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=        --enable-socks
.endif

# SSL support
.if defined(XCHAT_USE_SSL) && !empty(XCHAT_USE_SSL:M[Yy][Ee][Ss])
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=        --enable-openssl=${SSLBASE}
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/xchat/plugins

.include "../../mk/bsd.pkg.mk"

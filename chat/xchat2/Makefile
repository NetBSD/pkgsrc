# $NetBSD: Makefile,v 1.9 2003/07/13 13:50:49 wiz Exp $
#

DISTNAME=	xchat-2.0.3
PKGREVISION=	2
CATEGORIES=	chat gnome
MASTER_SITES=	http://www.xchat.org/files/source/2.0/
EXTRACT_SUFX=	.tar.bz2

PATCH_SITES=		http://www.xchat.org/files/source/2.0/patches/
PATCHFILES=		xc203-fix-cps.diff xc203-fixtint.diff
PATCH_DIST_STRIP=	-p1

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.xchat.org/
COMMENT=	X11 (X Window System) IRC client, using the GTK2 toolkit

BUILD_USES_MSGFMT=	YES
DEPENDS=		gnome2-dirs>=1.0:../../misc/gnome2-dirs

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
USE_GMAKE=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ARGS+=	--enable-tcl=no
CONFIGURE_ARGS+=	--disable-perl
CONFIGURE_ARGS+=	--disable-python

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
.  include "../../security/openssl/buildlink2.mk"
CONFIGURE_ARGS+=        --enable-openssl=${SSLBASE}
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/xchat/plugins

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"

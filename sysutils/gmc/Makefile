# $NetBSD: Makefile,v 1.6 1999/05/11 20:44:44 tron Exp $

DISTNAME=	mc-4.5.30
PKGNAME=	gmc-4.5.30
CATEGORIES=	sysutils gnome
MASTER_SITES=	ftp://ftp.gnome.org/pub/GNOME/gnome-1.0/sources/ \
		ftp://ftp.jimpick.com/pub/mirrors/gnome/gnome-1.0/sources/ \
		ftp://ftp.informatik.uni-bonn.de/pub/os/unix/gnome/gnome-1.0/sources/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.gnome.org/mc/

DEPENDS+=	libslang-1.2.2:../../devel/libslang
DEPENDS+=	gnome-core-1.0.5:../../x11/gnome-core

CONFLICTS+=	mc-*

GNU_CONFIGURE=		YES
USE_GMAKE=		yes
USE_X11BASE=		yes
# XXX the cat-id-tbl is not up to date, so the catgets is broken.
CONFIGURE_ARGS+=	--without-catgets --with-netrc --with-slang \
			--without-x --with-gnome --without-tk

# Funny stuff to get this to use the system libslang.
CONFIGURE_ENV+=		LIBS="-lm -ltermcap" CPPFLAGS="-I${LOCALBASE}/include"
CFLAGS+=		-Dunix -I${LOCALBASE}/include -DxBSD
LDFLAGS+=		-L${LOCALBASE}/lib
MAKE_ENV+=		INSTALL_SCRIPT="${INSTALL_SCRIPT}"

.include "../../mk/bsd.pkg.mk"

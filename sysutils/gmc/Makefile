# $NetBSD: Makefile,v 1.12 1999/08/17 18:28:40 rh Exp $

DISTNAME=	mc-4.5.37
PKGNAME=	gmc-4.5.37
CATEGORIES=	sysutils gnome
MASTER_SITES=	ftp://ftp.gnome.org/pub/GNOME/gnome-1.0/sources/ \
		ftp://ftp.sunet.se/pub/X11/GNOME/gnome-1.0/sources/ \
		ftp://ftp.informatik.uni-bonn.de/pub/os/unix/gnome/gnome-1.0/sources/ \
		ftp://ftp.tuwien.ac.at/hci/gnome.org/GNOME/sources/mc/ \
		http://gd.tuwien.ac.at/hci/gnome.org/GNOME/sources/mc/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.gnome.org/mc/

DEPENDS+=	gnome-core-1.0.7:../../x11/gnome-core
DEPENDS+=	libslang-1.3.8:../../devel/libslang

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

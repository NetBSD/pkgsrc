# $NetBSD: Makefile,v 1.20 1999/10/23 14:06:57 tron Exp $

DISTNAME=	mc-4.5.40
PKGNAME=	gmc-4.5.40
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=gnome-1.0.53/sources/}

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.gnome.org/mc/

DEPENDS+=	gnome-core-*:../../x11/gnome-core
DEPENDS+=	libslang-*:../../devel/libslang

CONFLICTS+=	mc-*

GNU_CONFIGURE=		YES
USE_GMAKE=		yes
USE_X11BASE=		yes
CONFIGURE_ARGS+=	--with-netrc --with-slang --without-x --with-gnome \
			--without-tk

# Funny stuff to get this to use the system libslang.
CONFIGURE_ENV+=		LIBS="-lm -ltermcap" CPPFLAGS="-I${LOCALBASE}/include"
CFLAGS+=		-Dunix -I${LOCALBASE}/include -DxBSD
LDFLAGS+=		-L${LOCALBASE}/lib

.include "../../mk/bsd.pkg.mk"

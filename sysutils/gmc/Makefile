# $NetBSD: Makefile,v 1.21 2000/01/11 01:33:06 tron Exp $

DISTNAME=	mc-4.5.42
PKGNAME=	gmc-4.5.42
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/mc/}

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

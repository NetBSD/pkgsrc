# $NetBSD: Makefile,v 1.22 2000/06/01 17:46:15 rh Exp $

DISTNAME=	mc-4.5.50
PKGNAME=	g${DISTNAME}
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

# $NetBSD: Makefile,v 1.34 2000/01/02 18:02:41 tron Exp $
# FreeBSD Id: Makefile,v 1.16 1997/11/30 19:37:48 vanilla Exp
#

DISTNAME=	mc-4.5.40
CATEGORIES=	sysutils

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.gnome.org/mc/
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/releases/gnome-1.0.53/}

DEPENDS+=	libslang-*:../../devel/libslang
DEPENDS+=	glib-1.2.*:../../devel/glib

CONFLICTS+=	gmc-*

GNU_CONFIGURE=		YES
USE_GMAKE=		YES
CONFIGURE_ARGS+=	--with-netrc --with-slang --without-x \
			--without-gnome --without-tk

# Funny stuff to get this to use the system libslang.
CONFIGURE_ENV+=		LIBS="-lm -ltermcap" CPPFLAGS="-I${LOCALBASE}/include"
CFLAGS+=		-Dunix -I${LOCALBASE}/include -DxBSD
LDFLAGS+=		-L${LOCALBASE}/lib

.include "../../mk/bsd.pkg.mk"

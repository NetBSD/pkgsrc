# $NetBSD: Makefile,v 1.29 1999/09/06 20:41:37 hubertf Exp $
# FreeBSD Id: Makefile,v 1.16 1997/11/30 19:37:48 vanilla Exp
#

DISTNAME=	mc-4.5.38
CATEGORIES=	sysutils

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.gnome.org/mc/
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/mc/}

DEPENDS+=	libslang-1.3.8:../../devel/libslang
DEPENDS+=	glib-1.2.4:../../devel/glib

CONFLICTS+=	gmc-*

GNU_CONFIGURE=		YES
USE_GMAKE=		yes
# XXX the cat-id-tbl is not up to date, so the catgets is broken.
CONFIGURE_ARGS+=	--without-catgets --with-netrc --with-slang \
			--without-x --without-gnome --without-tk

# Funny stuff to get this to use the system libslang.
CONFIGURE_ENV+=		LIBS="-lm -ltermcap" CPPFLAGS="-I${LOCALBASE}/include"
CFLAGS+=		-Dunix -I${LOCALBASE}/include -DxBSD
LDFLAGS+=		-L${LOCALBASE}/lib
MAKE_ENV+=		INSTALL_SCRIPT="${INSTALL_SCRIPT}"

.include "../../mk/bsd.pkg.mk"

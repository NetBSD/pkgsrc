# $NetBSD: Makefile,v 1.12 1998/10/04 17:16:21 tv Exp $
# FreeBSD Id: Makefile,v 1.16 1997/11/30 19:37:48 vanilla Exp
#

DISTNAME=		mc-4.1.35
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	utils/file/managers/mc

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnome.org/mc/

DEPENDS+=		libslang-1.2.2:../../devel/libslang

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-catgets --with-netrc --with-slang \
			--without-x --without-gnome --without-tk

# Funny stuff to get this to use the system libslang.
CONFIGURE_ENV+=		LIBS="-lm -ltermcap" CPPFLAGS="-I${LOCALBASE}/include"
CFLAGS+=		-Dunix -I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib

.include "../../mk/bsd.pkg.mk"

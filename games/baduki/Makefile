# $NetBSD: Makefile,v 1.9 2000/07/10 10:40:40 agc Exp $

DISTNAME=	baduki-0.2.9
CATEGORIES=	games
MASTER_SITES=	http://soback.kornet21.net/~artist/baduk/

MAINTAINER=	bad@netbsd.org
HOMEPAGE=	http://soback.kornet21.net/~artist/baduk/baduki.html

DEPENDS+=	gtk+-1.2.*:../../x11/gtk

USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-gtk-prefix=${GTK_PREFIX}
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ENV+=	GTK_CONFIG="${GTK_PREFIX}/bin/gtk-config"
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

GTK_PREFIX!=	${PKG_INFO} -qp gtk+ | ${AWK} '{print $$2}'

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.8 2000/06/30 10:04:46 agc Exp $

DISTNAME=	baduki-0.2.9
CATEGORIES=	games
MASTER_SITES=	http://soback.kornet21.net/~artist/baduk/

MAINTAINER=	bad@netbsd.org
HOMEPAGE=	http://soback.kornet21.net/~artist/baduk/baduki.html

DEPENDS+=	gtk+-1.2.*:../../x11/gtk

USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-gtk-prefix=${X11PREFIX} --without-included-gettext
CONFIGURE_ENV+=	GTK_CONFIG="${X11PREFIX}/bin/gtk-config"
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

.include "../../mk/bsd.pkg.mk"

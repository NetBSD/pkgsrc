# $NetBSD: Makefile,v 1.5 1999/09/10 19:56:13 bad Exp $

DISTNAME=	baduki-0.2.9
CATEGORIES=	games
MASTER_SITES=	http://soback.kornet21.net/~artist/baduk/

MAINTAINER=	bad@netbsd.org
HOMEPAGE=	http://soback.kornet21.net/~artist/baduk/baduki.html

DEPENDS+=	gettext-0.10.35:../../devel/gettext
DEPENDS+=	gtk10-1.0.6:../../x11/gtk10

USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-gtk-prefix=${X11BASE} --without-included-gettext
CONFIGURE_ENV+=	GTK_CONFIG="${X11BASE}/bin/gtk10-config"
LDFLAGS+=	-L$(LOCALBASE)/lib
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

.include "../../mk/bsd.pkg.mk"

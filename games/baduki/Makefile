# $NetBSD: Makefile,v 1.1.1.1 1999/01/31 22:03:43 bad Exp $

DISTNAME=	baduki-0.2
CATEGORIES=	games
MASTER_SITES=	http://soback.kornet21.net/~artist/baduk/

MAINTAINER=	bad@netbsd.org
HOMEPAGE=	http://soback.kornet21.net/~artist/baduk/baduki.html

DEPENDS+=	gettext-0.10.35:../../devel/gettext
DEPENDS+=	gtk+-1.0.6:../../x11/gtk10

BUILD_USES_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-gtk-prefix=${X11BASE} --without-included-gettext
LDFLAGS+=	-L$(LOCALBASE)/lib
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

.include "../../mk/bsd.pkg.mk"

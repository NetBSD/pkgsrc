# $NetBSD: Makefile,v 1.14 2000/11/02 04:24:50 itojun Exp $

DISTNAME=	baduki-0.2.9
CATEGORIES=	games
MASTER_SITES=	http://soback.kornet21.net/~artist/baduk/

MAINTAINER=	bad@netbsd.org
HOMEPAGE=	http://soback.kornet21.net/~artist/baduk/baduki.html

BUILD_DEPENDS+=	msgfmt:../../devel/gettext
DEPENDS+=	gtk+-1.2.*:../../x11/gtk

USE_X11=	yes
GNU_CONFIGURE=	yes
USE_LIBINTL=	yes

EVAL_PREFIX+=	GTKDIR=gtk+
CONFIGURE_ARGS+=	--with-gtk-prefix=${GTKDIR}
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ENV+=	GTK_CONFIG="${GTKDIR}/bin/gtk-config"
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

.include "../../mk/bsd.pkg.mk"

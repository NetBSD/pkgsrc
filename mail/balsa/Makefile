# $NetBSD: Makefile,v 1.44 2004/04/21 04:55:26 snj Exp $
#

DISTNAME=		balsa-1.4.3
PKGREVISION=		7
CATEGORIES=		mail gnome
MASTER_SITES=		http://www.theochem.kth.se/~pawsa/balsa/ \
			ftp://ftp.newton.cx/pub/balsa/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.balsa.net/
COMMENT=		GNOME EMail client

GNU_CONFIGURE=		yes
USE_DIRS+=		xdg-1.1
USE_LIBTOOL=		yes
USE_X11BASE=		yes
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes

CONFIGURE_DIRS=		${WRKSRC}
CONFIGURE_DIRS+=	${WRKSRC}/libmutt

CONFIGURE_ARGS+=	--no-recursion
CONFIGURE_ARGS+=	--disable-more-warnings
CONFIGURE_ARGS+=	--enable-pcre
CONFIGURE_ARGS+=        --with-ssl=${BUILDLINK_PREFIX.openssl}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libtool/buildlink3.mk"
.include "../../devel/libproplist/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../mail/libesmtp/buildlink3.mk"
.include "../../print/gnome-print/buildlink3.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

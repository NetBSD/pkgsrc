# $NetBSD: Makefile,v 1.41 2004/03/26 02:27:43 wiz Exp $
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

DEPENDS+=		xdg-x11-dirs>=1.1:../../misc/xdg-x11-dirs

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_X11BASE=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes

CONFIGURE_DIRS=		${WRKSRC}
CONFIGURE_DIRS+=	${WRKSRC}/libmutt

CONFIGURE_ARGS+=	--no-recursion
CONFIGURE_ARGS+=	--disable-more-warnings
CONFIGURE_ARGS+=	--enable-pcre
CONFIGURE_ARGS+=        --with-ssl=${BUILDLINK_PREFIX.openssl}

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/libtool/buildlink2.mk"
.include "../../devel/libproplist/buildlink2.mk"
.include "../../devel/pcre/buildlink2.mk"
.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../mail/libesmtp/buildlink2.mk"
.include "../../print/gnome-print/buildlink2.mk"
.include "../../textproc/aspell/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../sysutils/gnome-vfs/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"

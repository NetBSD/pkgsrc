# $NetBSD: Makefile,v 1.26 2002/12/01 15:37:58 salo Exp $
#

DISTNAME=	balsa-1.4.0
PKGREVISION=	1
CATEGORIES=	mail gnome
MASTER_SITES=	http://www.theochem.kth.se/~pawsa/balsa/ \
		ftp://ftp.newton.cx/pub/balsa/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.balsa.net/
COMMENT=	GNOME EMail client

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_X11BASE=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ARGS+=	--disable-more-warnings --without-esmtp \
			--enable-pcre 

CONFIGURE_ARGS+=        --with-ssl=${BUILDLINK_PREFIX.openssl}

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/libtool/buildlink2.mk"
.include "../../devel/libproplist/buildlink2.mk"
.include "../../devel/pcre/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../textproc/libpspell/buildlink2.mk"
.include "../../x11/gnome-core/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"

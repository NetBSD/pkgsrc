# $NetBSD: Makefile,v 1.20 2012/09/15 10:06:15 obache Exp $

DISTNAME=	libfprint-0.0.6
PKGREVISION=	18
CATEGORIES=	security devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fprint/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	plunky@rya-online.net
HOMEPAGE=	http://reactivated.net/fprint/wiki/Libfprint
COMMENT=	Fingerprint reader access library

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config autoconf automake autoheader autoreconf

CPPFLAGS+=	-DHAVE_MEMMEM

CONFIGURE_ARGS+=CRYPTO_CFLAGS=-I${SSLBASE}/include/openssl \
		CRYPTO_LIBS="-L${SSLBASE}/lib -lcrypto"

pre-configure:
	cd ${WRKSRC} && autoreconf -vif

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

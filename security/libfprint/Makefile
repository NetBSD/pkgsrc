# $NetBSD: Makefile,v 1.28 2014/02/12 23:18:33 tron Exp $

DISTNAME=	libfprint-0.0.6
PKGREVISION=	25
CATEGORIES=	security devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fprint/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	plunky@rya-online.net
HOMEPAGE=	http://reactivated.net/fprint/wiki/Libfprint
COMMENT=	Fingerprint reader access library

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

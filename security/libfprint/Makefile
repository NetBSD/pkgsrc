# $NetBSD: Makefile,v 1.35 2016/05/26 11:44:00 wiz Exp $

DISTNAME=	libfprint-0.0.6
PKGREVISION=	31
CATEGORIES=	security devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fprint/}
EXTRACT_SUFX=	.tar.bz2

HOMEPAGE=	http://reactivated.net/fprint/wiki/Libfprint
COMMENT=	Fingerprint reader access library
LICENSE=	gnu-lgpl-v2.1

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
.include "../../graphics/ImageMagick6/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.12 2026/04/19 17:31:59 wiz Exp $

DISTNAME=	libifp-1.0.1.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ifp-driver/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ifp-driver.sourceforge.net/
COMMENT=	General-purpose library-driver for iRiver's iFP portable players
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-libusb=${PREFIX}
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
USE_FEATURES+=		fts_open
# needs hardware plugged in
#TEST_TARGET=		check

CFLAGS.SunOS+=	-fPIC

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/libusb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

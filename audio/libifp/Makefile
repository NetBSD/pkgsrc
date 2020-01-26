# $NetBSD: Makefile,v 1.9 2020/01/26 05:26:11 rillig Exp $
#

DISTNAME=	libifp-1.0.0.2
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ifp-driver/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ifp-driver.sourceforge.net/
COMMENT=	General-purpose library-driver for iRiver's iFP portable players
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-libusb=${BUILDLINK_PREFIX.libusb}
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
USE_FEATURES+=		fts_open

CFLAGS.SunOS+=	-fPIC
LIBS.SunOS+=	-liconv

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/libusb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

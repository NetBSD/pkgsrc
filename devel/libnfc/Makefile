# $NetBSD: Makefile,v 1.1 2016/12/16 08:11:55 manu Exp $

DISTNAME=	libnfc-1.7.1
CATEGORIES=	net
MASTER_SITES=	https://dl.bintray.com/nfc-tools/sources/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nfc-tools.org/index.php?title=Libnfc
COMMENT=	Low level NFC SDK and Programmers API
LICENSE=	gnu-lgpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

CONFIGURE_ARGS+=--with-drivers=all
CONFIGURE_ARGS+=--enable-doc

BUILD_DEPENDS+=	doxygen>=1.8.11:../../devel/doxygen

.include "../../devel/libusb/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../security/pcsc-lite/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

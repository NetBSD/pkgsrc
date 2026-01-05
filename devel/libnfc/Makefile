# $NetBSD: Makefile,v 1.6 2026/01/05 09:17:23 wiz Exp $

DISTNAME=	libnfc-1.7.1
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://dl.bintray.com/nfc-tools/sources/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://nfc-tools.github.io/projects/libnfc/
COMMENT=	Low level NFC SDK and Programmers API
LICENSE=	gnu-lgpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

CONFIGURE_ARGS+=	--with-drivers=all
CONFIGURE_ARGS+=	--enable-doc

TOOL_DEPENDS+=	doxygen>=1.8.11:../../devel/doxygen

.include "../../mk/libusb.buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../security/pcsc-lite/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

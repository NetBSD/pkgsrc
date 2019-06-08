# $NetBSD: Makefile,v 1.7 2019/06/08 10:53:27 rillig Exp $
#

DISTNAME=	dfu-programmer-0.7.2
PKGREVISION=	1
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dfu-programmer/dfu-programmer/0.7.2/}

MAINTAINER=	jakllsch@NetBSD.org
HOMEPAGE=	http://dfu-programmer.sourceforge.net/
COMMENT=	Programmer for Atmel USB DFU Bootloader
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-libusb_1_0

.include "../../mk/libusb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

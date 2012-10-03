# $NetBSD: Makefile,v 1.3 2012/10/03 00:10:29 asau Exp $
#

DISTNAME=	dfu-programmer-0.5.4
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dfu-programmer/dfu-programmer/0.5.4/}

MAINTAINER=	jakllsch@NetBSD.org
HOMEPAGE=	http://dfu-programmer.sourceforge.net/
COMMENT=	Programmer for Atmel USB DFU Bootloader
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes

.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

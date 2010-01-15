# $NetBSD: Makefile,v 1.1.1.1 2010/01/15 22:00:19 jakllsch Exp $
#

DISTNAME=	dfu-programmer-0.5.2
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dfu-programmer/dfu-programmer/0.5.2/}

MAINTAINER=	jakllsch@NetBSD.org
HOMEPAGE=	http://dfu-programmer/dfu-programmer/0.5.2.sourceforge.net/
COMMENT=	Programmer for Atmel USB DFU Bootloader
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

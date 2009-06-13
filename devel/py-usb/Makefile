# $NetBSD: Makefile,v 1.2 2009/06/13 06:46:48 rillig Exp $

VERSION=	0.4.1
DISTNAME=	pyusb-${VERSION}
PKGNAME=	${PYPKGPREFIX}-usb-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyusb/}

MAINTAINER=	wiml@hhhh.org
HOMEPAGE=	http://pyusb.berlios.de/
COMMENT=	Python interface to USB via libusb

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

.include "../../devel/libusb/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"

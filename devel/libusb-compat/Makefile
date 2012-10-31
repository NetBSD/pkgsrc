# $NetBSD: Makefile,v 1.3 2012/10/31 11:17:23 asau Exp $

DISTNAME=	libusb-compat-0.1.4
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libusb/libusb-compat-0.1/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.libusb.org/wiki/libusb-compat-0.1
COMMENT=	USB access library version 0 compatibility layer on top of version 1
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	libusb.pc.in

CONFLICTS=		libusb-[0-9]*

.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

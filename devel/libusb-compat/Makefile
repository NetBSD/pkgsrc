# $NetBSD: Makefile,v 1.1.1.1 2012/05/30 15:42:04 wiz Exp $

DISTNAME=	libusb-compat-0.1.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libusb/libusb-compat-0.1/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.libusb.org/wiki/libusb-compat-0.1
COMMENT=	USB access library version 0 compatibility layer on top of version 1
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	libusb.pc.in

CONFLICTS=		libusb-[0-9]*

.include "../../devel/libusbx/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.6 2017/09/30 07:44:12 wiz Exp $

DISTNAME=	libusb-compat-0.1.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libusb/libusb-compat-0.1/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libusb/libusb/wiki
COMMENT=	USB access library version 0 compatibility layer on top of version 1
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	libusb.pc.in

CPPFLAGS.SunOS+=	-Du_int8_t=uint8_t
CPPFLAGS.SunOS+=	-Du_int16_t=uint16_t
CPPFLAGS.SunOS+=	-Du_int32_t=uint32_t

CONFLICTS=		libusb-[0-9]*

.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.12 2023/12/07 18:25:12 wiz Exp $

DISTNAME=	libusb-compat-0.1.8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=libusb/}
GITHUB_PROJECT=	libusb-compat-0.1
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libusb/libusb/wiki
COMMENT=	USB access library version 0 compatibility layer on top of version 1
LICENSE=	gnu-lgpl-v2.1

CONFLICTS=	libusb-[0-9]*

DIST_SUBDIR=	${PKGNAME_NOREV}
USE_LIBTOOL=	yes
USE_TOOLS+=	gsed pkg-config
GNU_CONFIGURE=	yes

PKGCONFIG_OVERRIDE+=	libusb.pc.in

.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

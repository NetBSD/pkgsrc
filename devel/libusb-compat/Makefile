# $NetBSD: Makefile,v 1.9 2020/10/08 11:54:44 triaxx Exp $

DISTNAME=	libusb-compat-0.1.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=libusb/}
GITHUB_PROJECT=	libusb-compat-0.1
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libusb/libusb/wiki
COMMENT=	USB access library version 0 compatibility layer on top of version 1
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=		yes
USE_TOOLS+=		gsed pkg-config
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	libusb.pc.in

CONFLICTS=		libusb-[0-9]*

.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

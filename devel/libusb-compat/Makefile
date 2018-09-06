# $NetBSD: Makefile,v 1.8 2018/09/06 13:10:01 jperkin Exp $

GITHUB_PROJECT=	libusb-compat-0.1
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	libusb-compat-0.1.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=libusb/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libusb/libusb/wiki
COMMENT=	USB access library version 0 compatibility layer on top of version 1
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=		yes
USE_TOOLS+=		gsed pkg-config
USE_TOOLS+=		aclocal autoconf automake autoheader
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	libusb.pc.in

CONFLICTS=		libusb-[0-9]*

pre-configure:
	cd ${WRKSRC} && sh autogen.sh

.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

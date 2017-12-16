# $NetBSD: Makefile,v 1.7 2017/12/16 22:53:15 khorben Exp $

DISTNAME=	libusb-compat-0.1.6rc2
GITHUB_PROJECT=	libusb-compat-0.1
GITHUB_TAG=	v0.1.6-rc2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=libusb/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libusb/libusb/wiki
COMMENT=	USB access library version 0 compatibility layer on top of version 1
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
USE_TOOLS+=		aclocal autoconf automake autoheader
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	libusb.pc.in

CONFLICTS=		libusb-[0-9]*

pre-configure:
	cd ${WRKSRC} && sh autogen.sh

.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

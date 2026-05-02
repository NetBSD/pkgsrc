# $NetBSD: Makefile,v 1.2 2026/05/02 05:49:35 vins Exp $

DISTNAME=	libusbmuxd-2.1.1
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_GITHUB:=libimobiledevice/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.libimobiledevice.org/
COMMENT=	Communication interface library for usbmuxd
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	src/libusbmuxd-2.0.pc.in

.include "../../textproc/libplist/buildlink3.mk"
.include "../../misc/libimobiledevice-glue/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

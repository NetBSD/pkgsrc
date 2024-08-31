# $NetBSD: Makefile,v 1.1 2024/08/31 19:41:34 jakllsch Exp $

DISTNAME=	libjaylink-0.3.1
CATEGORIES=	misc devel
MASTER_SITES=	https://gitlab.zapb.de/libjaylink/libjaylink/-/archive/0.3.1/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.zapb.de/libjaylink/libjaylink/-/archive/0.3.1/
COMMENT=	Access SEGGER J-Link and compatible devices
LICENSE=	gnu-gpl-v2

PKGCONFIG_OVERRIDE+=	libjaylink.pc.in

USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf autoreconf automake pkg-config
GNU_CONFIGURE=		yes

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} sh ./autogen.sh

.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

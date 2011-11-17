# $NetBSD: Makefile,v 1.2 2011/11/17 18:17:48 jakllsch Exp $

DISTNAME=	libftdi-0.19
CATEGORIES=	devel
MASTER_SITES=	http://www.intra2net.com/en/developer/libftdi/download/

MAINTAINER=	jakllsch@NetBSD.org
HOMEPAGE=	http://www.intra2net.com/en/developer/libftdi/
COMMENT=	userland driver library for FTDI USB chips
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--without-examples
CONFIGURE_ARGS+=	--without-docs

PKGCONFIG_OVERRIDE+=	libftdi.pc.in
PKGCONFIG_OVERRIDE+=	libftdipp.pc.in

.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.6 2011/07/28 21:54:08 pettai Exp $
#

DISTNAME=	log4shib-1.0.4
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.shibboleth.net/downloads/log4shib/${PKGVERSION_NOREV}/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://shibboleth.internet2.edu/
COMMENT=	C++ library for flexible logging, modeled after Log4j
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEFS+=	VARBASE

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--disable-doxygen

USE_TOOLS+=	pkg-config

USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	log4shib.pc.in

.include "../../mk/bsd.pkg.mk"

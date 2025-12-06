# $NetBSD: Makefile,v 1.13 2025/12/06 23:43:36 maya Exp $

DISTNAME=	log4shib-1.0.9
CATEGORIES=	devel
MASTER_SITES=	http://www.shibboleth.net/downloads/log4shib/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://shibboleth.internet2.edu/
COMMENT=	C++ library for flexible logging, modeled after Log4j
LICENSE=	gnu-lgpl-v2.1

BUILD_DEFS+=	VARBASE

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--disable-doxygen

USE_TOOLS+=	pkg-config

USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

# Uses dynamic exceptions which are removed in C++17.
FORCE_CXX_STD=	c++11

PKGCONFIG_OVERRIDE+=	log4shib.pc.in

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

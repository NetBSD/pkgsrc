# $NetBSD: Makefile,v 1.2 2010/03/16 07:15:44 pettai Exp $
#

DISTNAME=	log4shib-1.0.4
CATEGORIES=	devel
MASTER_SITES=	http://shibboleth.internet2.edu/downloads/log4shib/1.0.4/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://shibboleth.internet2.edu/
COMMENT=	C++ library for flexible logging, modeled after Log4j
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEFS+=	VARBASE

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

USE_TOOLS+=	pkg-config

USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	log4shib.pc.in

.include "../../mk/bsd.pkg.mk"

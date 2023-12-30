# $NetBSD: Makefile,v 1.34 2023/12/30 01:22:35 zafer Exp $

DISTNAME=	cppunit-1.15.1
CATEGORIES=	devel
MASTER_SITES=	https://dev-www.libreoffice.org/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.freedesktop.org/wiki/Software/cppunit
COMMENT=	C++ unit testing framework
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

USE_CXX_FEATURES+=	c++11

CONFIGURE_ARGS+=	--disable-werror

PKGCONFIG_OVERRIDE=	cppunit.pc.in

.include "options.mk"
.include "../../mk/bsd.pkg.mk"

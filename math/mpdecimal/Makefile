# $NetBSD: Makefile,v 1.1 2024/12/24 10:52:58 wiz Exp $

DISTNAME=	mpdecimal-4.0.0
CATEGORIES=	math
MASTER_SITES=	https://www.bytereef.org/software/mpdecimal/releases/

MAINTAINER=	skrah@bytereef.org
HOMEPAGE=	https://www.bytereef.org/mpdecimal/
COMMENT=	C/C++ arbitrary precision decimal floating point libraries
LICENSE=	2-clause-bsd

USE_CC_FEATURES=	c99
USE_CXX_FEATURES=	c++11
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
BUILD_TARGET=		default
TEST_TARGET=		check_local
# Let libmpdec++.so find libmpdec.so
CONFIGURE_ENV+=		LDXXFLAGS="${COMPILER_RPATH_FLAG}${PREFIX}/lib"
PKGCONFIG_OVERRIDE+=	libmpdec/.pc/libmpdec.pc.in
PKGCONFIG_OVERRIDE+=	libmpdec++/.pc/libmpdec++.pc.in

.include "../../mk/bsd.pkg.mk"

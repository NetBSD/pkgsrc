# $NetBSD: Makefile,v 1.59 2024/08/25 06:18:31 wiz Exp $

DISTNAME=	soci-4.0.3
PKGREVISION=	5
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=soci/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://soci.sourceforge.net/
COMMENT=	C++ database access library
LICENSE=	boost-license

USE_LANGUAGES=	c gnu++11

CMAKE_CONFIGURE_ARGS+=	-DSOCI_LIBDIR=lib
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_CXX_FLAGS=${CXXFLAGS:Q}
CMAKE_CONFIGURE_ARGS+=	-DWITH_ODBC=OFF
CMAKE_CONFIGURE_ARGS+=	-DWITH_ORACLE=OFF
CMAKE_CONFIGURE_ARGS+=	-DWITH_FIREBIRD=OFF
CMAKE_CONFIGURE_ARGS+=	-DWITH_DB2=OFF

.include "options.mk"

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"

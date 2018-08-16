# $NetBSD: Makefile,v 1.29 2018/08/16 18:54:39 adam Exp $
#

DISTNAME=	soci-3.2.2
PKGREVISION=	25
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=soci/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://soci.sourceforge.net/
COMMENT=	C++ database access library
LICENSE=	boost-license

USE_CMAKE=	yes
USE_LANGUAGES=	c gnu++11

CMAKE_ARGS+=	-DSOCI_LIBDIR=lib
CMAKE_ARGS+=	-DCMAKE_CXX_FLAGS=${CXXFLAGS:Q}

.include "options.mk"
.include "../../mk/bsd.pkg.mk"

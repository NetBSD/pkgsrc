# $NetBSD: Makefile,v 1.19 2017/04/22 21:03:28 adam Exp $
#

DISTNAME=	soci-3.2.2
PKGREVISION=	16
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=soci/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://soci.sourceforge.net/
COMMENT=	C++ database access library
LICENSE=	boost-license

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DSOCI_LIBDIR=lib

.include "../../mk/bsd.prefs.mk"

CXXFLAGS.Cygwin+=	-std=gnu++11
CMAKE_ARGS+=	-DCMAKE_CXX_FLAGS=${CXXFLAGS:Q}

.include "options.mk"
.include "../../mk/bsd.pkg.mk"

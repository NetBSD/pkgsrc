# $NetBSD: Makefile,v 1.12 2015/04/17 15:53:00 adam Exp $
#

DISTNAME=	soci-3.2.2
PKGREVISION=	9
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

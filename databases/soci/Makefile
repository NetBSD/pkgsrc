# $NetBSD: Makefile,v 1.14 2016/04/11 19:01:46 ryoon Exp $
#

DISTNAME=	soci-3.2.2
PKGREVISION=	11
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

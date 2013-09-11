# $NetBSD: Makefile,v 1.4 2013/09/11 12:22:33 joerg Exp $
#

DISTNAME=	soci-3.2.2
PKGREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=soci/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://soci.sourceforge.net/
COMMENT=	C++ database access library
LICENSE=	boost-license

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DSOCI_LIBDIR=lib

.include "options.mk"
.include "../../mk/bsd.pkg.mk"

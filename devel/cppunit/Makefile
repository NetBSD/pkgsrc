# $NetBSD: Makefile,v 1.8.2.1 2006/08/03 17:51:01 ghen Exp $
#

DISTNAME=	cppunit-1.10.2
PKGREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cppunit/}

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://cppunit.sourceforge.net/
COMMENT=	CppUnit is a C++ unit testing framework

BUILD_DEPENDS+=	doxygen>=1.4.7:../../devel/doxygen

USE_LIBTOOL=	yes
USE_LANGUAGES+=	c++
USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"

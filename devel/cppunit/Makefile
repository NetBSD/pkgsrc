# $NetBSD: Makefile,v 1.2 2004/10/04 13:21:15 wulf Exp $
#

DISTNAME=	cppunit-1.10.2
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cppunit/}

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://cppunit.sourceforge.net/
COMMENT=	CppUnit is a C++ unit testing framework

BUILD_DEPENDS+=	doxygen>=1.3.6:../../devel/doxygen

USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"

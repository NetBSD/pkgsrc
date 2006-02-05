# $NetBSD: Makefile,v 1.7 2006/02/05 23:08:40 joerg Exp $
#

DISTNAME=	cppunit-1.10.2
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cppunit/}

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://cppunit.sourceforge.net/
COMMENT=	CppUnit is a C++ unit testing framework

BUILD_DEPENDS+=	doxygen>=1.3.6:../../devel/doxygen

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.17 2010/06/11 23:20:07 wiz Exp $
#

DISTNAME=	cppunit-1.10.2
PKGREVISION=	12
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cppunit/}

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://cppunit.sourceforge.net/
COMMENT=	CppUnit is a C++ unit testing framework
LICENSE=	gnu-lgpl-v2.1

BUILD_DEPENDS+=	doxygen>=1.6.3:../../devel/doxygen

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.19 2011/02/28 14:52:44 wiz Exp $
#

DISTNAME=	cppunit-1.12.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cppunit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cppunit.sourceforge.net/
COMMENT=	CppUnit is a C++ unit testing framework
LICENSE=	gnu-lgpl-v2.1

BUILD_DEPENDS+=	doxygen>=1.6.3:../../devel/doxygen

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

PKGCONFIG_OVERRIDE=	cppunit.pc.in

SUBST_CLASSES+=		rpath
SUBST_SED.rpath=	-e s';-L@libdir@;${COMPILER_RPATH_FLAG}@libdir@ -L@libdir@;g'
SUBST_FILES.rpath=	cppunit-config.in
SUBST_STAGE.rpath=	pre-configure
SUBST_MESSAGE.rpath=	Adding rpath to cppunit-config.

.include "../../mk/bsd.pkg.mk"

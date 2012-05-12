# $NetBSD: Makefile,v 1.21 2012/05/12 05:33:11 adam Exp $

DISTNAME=	cppunit-1.12.1
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cppunit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cppunit.sourceforge.net/
COMMENT=	CppUnit is a C++ unit testing framework
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE=	cppunit.pc.in

SUBST_CLASSES+=		rpath
SUBST_SED.rpath=	-e s';-L@libdir@;${COMPILER_RPATH_FLAG}@libdir@ -L@libdir@;g'
SUBST_FILES.rpath=	cppunit-config.in
SUBST_STAGE.rpath=	pre-configure
SUBST_MESSAGE.rpath=	Adding rpath to cppunit-config.

.include "options.mk"

.include "../../mk/bsd.pkg.mk"

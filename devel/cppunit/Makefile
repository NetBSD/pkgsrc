# $NetBSD: Makefile,v 1.22 2012/08/12 16:01:34 wiz Exp $

DISTNAME=	cppunit-1.13.0
CATEGORIES=	devel
MASTER_SITES=	http://dev-www.libreoffice.org/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/wiki/Software/cppunit
COMMENT=	C++ unit testing framework
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

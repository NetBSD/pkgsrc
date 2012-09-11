# $NetBSD: Makefile,v 1.3 2012/09/11 20:36:18 asau Exp $

DISTNAME=	tbb30_20110325oss_src
PKGNAME=	threadingbuildingblocks-3.0.6 # for "3.0 update 6"
CATEGORIES=	parallel
MASTER_SITES=	http://threadingbuildingblocks.org/uploads/76/168/3.0%20update%206/
EXTRACT_SUFX=	.tgz

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://www.threadingbuildingblocks.org/
COMMENT=	Threading Buildling Blocks

WRKSRC=		$(WRKDIR)/$(DISTNAME:_src=) #tbb30_20101215oss

USE_LANGUAGES=	c c++
USE_TOOLS=	gmake pax
MAKE_FLAGS=	tbb_build_prefix=build # use fixed path
BUILD_TARGET=	default
TEST_TARGET=	test

post-extract:
	cd $(WRKSRC)/build/ && cp FreeBSD.gcc.inc NetBSD.gcc.inc && cp FreeBSD.inc NetBSD.inc

INSTALLATION_DIRS=	include lib share/doc/$(PKGBASE)

do-install:
	$(INSTALL_LIB) $(WRKSRC)/build/build_release/libtbb.so $(DESTDIR)$(PREFIX)/lib/
	$(INSTALL_LIB) $(WRKSRC)/build/build_release/libtbbmalloc.so $(DESTDIR)$(PREFIX)/lib/
	$(INSTALL_LIB) $(WRKSRC)/build/build_debug/libtbb_debug.so $(DESTDIR)$(PREFIX)/lib/
	$(INSTALL_LIB) $(WRKSRC)/build/build_debug/libtbbmalloc_debug.so $(DESTDIR)$(PREFIX)/lib/
	(cd $(WRKSRC)/include && pax -rw tbb $(DESTDIR)$(PREFIX)/include/)
# documentation:
#	(cd $(WRKSRC)/doc/html && pax -rw . $(DESTDIR)$(PREFIX)/share/doc/html/$(PKGBASE)/)
#	$(INSTALL_DATA) $(WRKSRC)/doc/Release_Notes.txt $(DESTDIR)$(PREFIX)/share/doc/$(PKGBASE)/

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.2 1999/10/17 18:36:33 fredb Exp $
#

DISTNAME=	hfsutils-3.2.6
PKGNAME=	libhfs-3.2.6
CATEGORIES=	devel sysutils
MASTER_SITES=	ftp://ftp.mars.org/pub/hfs/

MAINTAINER=	wrstuden@netbsd.org
HOMEPAGE=	http://www.mars.org/home/rob/proj/hfs/

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS=-I./

USE_LIBTOOL=	yes

ALL_TARGET=	all_lib

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/libhfs
	cd ${WRKSRC}/libhfs; \
	  ${LIBTOOL} --mode=install ${INSTALL_PROGRAM} libhfs.la ${PREFIX}/lib; \
	  ${INSTALL_DATA} apple.h data.h hfs.h libhfs.h ${PREFIX}/include/libhfs
	cd ${WRKSRC}/librsrc; \
	  ${LIBTOOL} --mode=install ${INSTALL_PROGRAM} librsrc.la ${PREFIX}/lib; \
	  ${INSTALL_DATA} librsrc.h rsrc.h ${PREFIX}/include/libhfs
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libhfs
	cd ${WRKSRC}/doc; ${INSTALL_DATA} charset.txt libhfs.txt librsrc.txt \
	  ${PREFIX}/share/doc/libhfs

.include "../../mk/bsd.pkg.mk"

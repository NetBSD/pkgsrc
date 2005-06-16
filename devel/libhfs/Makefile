# $NetBSD: Makefile,v 1.14 2005/06/16 06:57:46 jlam Exp $
#

DISTNAME=	hfsutils-3.2.6
PKGNAME=	libhfs-3.2.6
PKGREVISION=	1
CATEGORIES=	devel sysutils
MASTER_SITES=	ftp://ftp.mars.org/pub/hfs/

MAINTAINER=	wrstuden@NetBSD.org
HOMEPAGE=	http://www.mars.org/home/rob/proj/hfs/
COMMENT=	Library for accessing HFS (Apple Macintosh) volumes

GNU_CONFIGURE=	yes

CPPFLAGS=	-I.

USE_LIBTOOL=	yes

BUILD_TARGET=	all_lib

INSTALLATION_DIRS=	lib

pre-patch:
	for f in librsrc/librsrc.h libhfs/libhfs.h; do \
	  ${MV} ${WRKSRC}/$$f ${WRKSRC}/$$f-prepatch; \
	  ${SED} -e '/Id/s|\$$||g' ${WRKSRC}/$$f-prepatch > ${WRKSRC}/$$f; \
	done

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

# $NetBSD: Makefile,v 1.4 2000/06/01 11:23:22 rh Exp $
#

DISTNAME=	hfsutils-3.2.6
PKGNAME=	libhfs-3.2.6
CATEGORIES=	devel sysutils
MASTER_SITES=	ftp://ftp.mars.org/pub/hfs/

MAINTAINER=	wrstuden@netbsd.org
HOMEPAGE=	http://www.mars.org/home/rob/proj/hfs/

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS=-I./

USE_PKGLIBTOOL=	yes

ALL_TARGET=	all_lib

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

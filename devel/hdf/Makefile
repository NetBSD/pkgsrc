# $NetBSD: Makefile,v 1.12 2002/05/03 23:14:52 jtb Exp $

DISTNAME=		HDF4.1r5
PKGNAME=		hdf-4.1r5
CATEGORIES=		devel
MASTER_SITES=		ftp://hdf.ncsa.uiuc.edu/HDF/HDF4.1r5/tar/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://hdf.ncsa.uiuc.edu/hdf4.html
COMMENT=		NCSA Hierarchical Data Format

USE_FORTRAN=		# defined
USE_BUILDLINK_ONLY=	# defined

post-patch:
	${MV} -f ${WRKSRC}/mfhdf/libsrc/netcdf.h.in 		\
	${WRKSRC}/mfhdf/libsrc/netcdf.h
	${MV} -f ${WRKSRC}/mfhdf/fortran/config/netcdf-fbsd.inc	\
	${WRKSRC}/mfhdf/fortran/netcdf.inc
	${MV} -f ${WRKSRC}/mfhdf/ncdump/ncdump.1		\
	${WRKSRC}/mfhdf/ncdump/hdfncdump.1
	${MV} -f ${WRKSRC}/mfhdf/ncgen/ncgen.1			\
	${WRKSRC}/mfhdf/ncgen/hdfncgen.1

post-install:
	${INSTALL_DATA} ${WRKSRC}/mfhdf/fortran/netcdf.inc 	\
		${PREFIX}/include/hdf

test:	build
	@cd ${WRKSRC}/hdf/test && ${SETENV} ${MAKE_ENV} ${MAKE}
	@cd ${WRKSRC}/hdf/test && ./testhdf
	@cd ${WRKSRC}/hdf/test && ./fortest
	@cd ${WRKSRC}/mfhdf/dumper && ${SH} testhdp.sh
	@cd ${WRKSRC}/mfhdf/ncdump && ${SETENV} ${MAKE_ENV} ${MAKE} test
	@cd ${WRKSRC}/mfhdf/nctest && ${SETENV} ${MAKE_ENV} ${MAKE} test

.include "../../devel/zlib/buildlink.mk"
.include "../../graphics/jpeg/buildlink.mk"
.include "../../mk/bsd.pkg.mk"

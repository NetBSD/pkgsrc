# $NetBSD: Makefile,v 1.9 2001/04/14 21:43:41 jtb Exp $

DISTNAME=	HDF4.1r4
PKGNAME=	hdf-4.1r4
CATEGORIES=	devel
MASTER_SITES=	ftp://hdf.ncsa.uiuc.edu/HDF/HDF/HDF_Current/tar/ \
		ftp://sunsite.doc.ic.ac.uk/packages/HDF/HDF/HDF_Current/tar/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://hdf.ncsa.uiuc.edu/hdf4.html
COMMENT=	NCSA Hierarchical Data Format

DEPENDS+=	jpeg-[0-9]*:../../graphics/jpeg

USE_FORTRAN=	#defined

EVAL_PREFIX+=	JPEGBASE=jpeg

# This is ugly, but saves 31 patches
post-patch:
	for i in fortran/config/jackets-fbsd.c			\
	fortran/fort_ps/mfhdfp.h fortran/jackets.src		\
	libsrc/cdftest.c libsrc/globdef.c libsrc/local_nc.h	\
	libsrc/xdrposix.c libsrc/xdrstdio.c ncdump/dumplib.c	\
	ncdump/vardata.c ncgen/generate.c ncgen/ncgen.h		\
	libsrc/mfhdf.h nctest/add.c nctest/atttests.c		\
	nctest/cdftests.c nctest/dimtests.c nctest/driver.c	\
	nctest/error.c nctest/misctest.c nctest/rec.c		\
	nctest/slabs.c nctest/val.c nctest/vardef.c		\
	nctest/varget.c nctest/vargetg.c nctest/varput.c	\
	nctest/varputg.c nctest/vartests.c nctest/vputget.c	\
	nctest/vputgetg.c; do					\
	${SED} -e 's:"netcdf.h":"netcdf_hdf.h":g'		\
		-e 's:\<netcdf.h\>:\<netcdf_hdf.h\>:g'		\
	${WRKSRC}/mfhdf/$$i > ${WRKSRC}/mfhdf/$$i.tmp		\
	&& ${MV} -f ${WRKSRC}/mfhdf/$$i.tmp			\
	${WRKSRC}/mfhdf/$$i;					\
	done
	${MV} -f ${WRKSRC}/mfhdf/libsrc/netcdf.h.in 		\
	${WRKSRC}/mfhdf/libsrc/netcdf_hdf.h
	${MV} -f ${WRKSRC}/mfhdf/fortran/config/netcdf-fbsd.inc	\
	${WRKSRC}/mfhdf/fortran/netcdf_hdf.inc
	${MV} -f ${WRKSRC}/mfhdf/ncdump/ncdump.1		\
	${WRKSRC}/mfhdf/ncdump/hdfncdump.1
	${MV} -f ${WRKSRC}/mfhdf/ncgen/ncgen.1			\
	${WRKSRC}/mfhdf/ncgen/hdfncgen.1

# XXX Don't compile this file with optimization.
pre-configure:
	${CC} ${FILESDIR}/bytesex.c -o ${WRKSRC}/bytesex

SWAP=	`${WRKSRC}/bytesex`

do-configure:
	@for f in libsrc dumper ncgen ncdump; do		\
		${SED} -e 's:@SWAP@:'${SWAP}':g'		\
		${WRKSRC}/mfhdf/$$f/Makefile >			\
		${WRKSRC}/mfhdf/$$f/Makefile.tmp		\
		&& ${MV} ${WRKSRC}/mfhdf/$$f/Makefile.tmp	\
		${WRKSRC}/mfhdf/$$f/Makefile;			\
	done

post-install:
	${INSTALL_DATA} ${WRKSRC}/mfhdf/fortran/netcdf_hdf.inc \
	${PREFIX}/include/hdf

test:	build
	@cd ${WRKSRC}/hdf/test && ${SETENV} ${MAKE_ENV} ${MAKE}
	@cd ${WRKSRC}/hdf/test && ./testhdf
	@cd ${WRKSRC}/hdf/test && ./fortest
	@cd ${WRKSRC}/mfhdf/dumper && ${SH} testhdp.sh
	@cd ${WRKSRC}/mfhdf/ncdump && ${SETENV} ${MAKE_ENV} ${MAKE} test
	@cd ${WRKSRC}/mfhdf/nctest && ${SETENV} ${MAKE_ENV} ${MAKE} test

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.1.1.1 2001/02/28 22:18:38 jtb Exp $

DISTNAME=	HDF4.1r4
PKGNAME=	hdf-4.1r4
CATEGORIES=	devel
MASTER_SITES=	ftp://hdf.ncsa.uiuc.edu/HDF/HDF/HDF_Current/tar/ \
		ftp://sunsite.doc.ic.ac.uk/packages/HDF/HDF/HDF_Current/tar/

MAINTAINER=	jtb@netbsd.org
HOMEPAGE=	http://hdf.ncsa.uiuc.edu/hdf4.html
COMMENT=	NCSA Hierarchical Data Format

DEPENDS+=	f2c-[0-9]*:../../lang/f2c
DEPENDS+=	jpeg-[0-9]*:../../graphics/jpeg

EVAL_PREFIX+=	JPEGBASE=jpeg F2CBASE=f2c
MAKE_ENV+=	"JPEGBASE=${JPEGBASE}"
MAKE_ENV+=	"F2CBASE=${F2CBASE}"

post-patch:
	(cd ${WRKSRC}/hdf/src; for i in *.f; do			\
		${F2CBASE}/bin/f2c $$i;				\
	done)
	(cd ${WRKSRC}/mfhdf/fortran; for i in *.f; do		\
		${F2CBASE}/bin/f2c $$i;				\
	done)
	for i in `${FIND} ${WRKSRC}/mfhdf/ -type f -print`; do	\
	${SED} -e 's:"netcdf.h":"netcdf_hdf.h":g'		\
		-e 's:\<netcdf.h\>:\<netcdf_hdf.h\>:g'		\
		< $$i > $$i.tmp && ${MV} -f $$i.tmp $$i;	\
	done
	${MV} -f ${WRKSRC}/mfhdf/libsrc/netcdf.h.in 		\
	${WRKSRC}/mfhdf/libsrc/netcdf_hdf.h
	${MV} -f ${WRKSRC}/mfhdf/ncdump/ncdump.1		\
	${WRKSRC}/mfhdf/ncdump/hdfncdump.1
	${MV} -f ${WRKSRC}/mfhdf/ncgen/ncgen.1			\
	${WRKSRC}/mfhdf/ncgen/hdfncgen.1

pre-configure:
	${CC} ${FILESDIR}/bytesex.c -o ${WRKSRC}/bytesex

SWAP=`${WRKSRC}/bytesex`

do-configure:
	@for f in libsrc dumper ncgen ncdump; do		\
		${SED} -e 's:@SWAP@:'${SWAP}':g'		\
		< ${WRKSRC}/mfhdf/$$f/Makefile >		\
		${WRKSRC}/mfhdf/$$f/Makefile.tmp		\
		&& ${MV} ${WRKSRC}/mfhdf/$$f/Makefile.tmp	\
		${WRKSRC}/mfhdf/$$f/Makefile;			\
	done

post-install:
	${INSTALL_DATA} ${WRKSRC}/mfhdf/fortran/config/netcdf-fbsd.inc \
	${PREFIX}/include/hdf/netcdf_hdf.inc

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.18 2004/04/25 02:16:42 snj Exp $

DISTNAME=		HDF4.2r0
PKGNAME=		hdf-4.2r0
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.ncsa.uiuc.edu/HDF/HDF/HDF4.2r0/src/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://hdf.ncsa.uiuc.edu/hdf4.html
COMMENT=		NCSA Hierarchical Data Format

USE_FORTRAN=		# defined
USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-szlib
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/hdf

post-patch:
	${MV} -f ${WRKSRC}/mfhdf/ncdump/ncdump.1		\
	${WRKSRC}/mfhdf/ncdump/hdfncdump.1
	${MV} -f ${WRKSRC}/mfhdf/ncgen/ncgen.1			\
	${WRKSRC}/mfhdf/ncgen/hdfncgen.1

do-test:
	@cd ${WRKSRC}/hdf/test && ${SETENV} ${MAKE_ENV} ${MAKE} check
	@cd ${WRKSRC}/mfhdf/dumper && ${SH} testhdp.sh
	@cd ${WRKSRC}/mfhdf/ncdump && ${SETENV} ${MAKE_ENV} ${MAKE} check
	@cd ${WRKSRC}/mfhdf/nctest && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../archivers/szip/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

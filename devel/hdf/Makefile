# $NetBSD: Makefile,v 1.42 2022/04/24 21:50:48 tnn Exp $

DISTNAME=	hdf-4.2.15
CATEGORIES=	devel
MASTER_SITES=	https://support.hdfgroup.org/ftp/HDF/releases/HDF${PKGVERSION_NOREV}/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://support.hdfgroup.org/products/hdf4/
COMMENT=	NCSA Hierarchical Data Format

USE_LIBTOOL=		yes
USE_TOOLS+=		lex gmake yacc
USE_LANGUAGES=		c fortran77
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/hdf
CONFIGURE_ARGS+=	--with-szlib
# pkgsrc libtool builds shared objects anyway
#CONFIGURE_ARGS+=	--enable-shared

.include "../../mk/compiler.mk"

.if empty(GFORTRAN_VERSION:M[0-9])
# gfortran>=10 requires this, earlier compilers don't
FFLAGS=			-O -fallow-argument-mismatch
.endif

# conflicts with devel/netcdf
post-install:
	mv ${DESTDIR}${PREFIX}/bin/ncdump ${DESTDIR}${PREFIX}/bin/hdfncdump
	mv ${DESTDIR}${PREFIX}/bin/ncgen ${DESTDIR}${PREFIX}/bin/hdfncgen
	mv ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/ncdump.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/hdfncdump.1
	mv ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/ncgen.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/hdfncgen.1

do-test:
	@cd ${WRKSRC}/hdf/test && ${SETENV} ${MAKE_ENV} ${MAKE} check
	@cd ${WRKSRC}/mfhdf/dumper && ${SH} testhdp.sh
	@cd ${WRKSRC}/mfhdf/ncdump && ${SETENV} ${MAKE_ENV} ${MAKE} check
	@cd ${WRKSRC}/mfhdf/nctest && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include "../../archivers/libaec/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

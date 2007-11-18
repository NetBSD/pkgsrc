# $NetBSD: Makefile,v 1.29 2007/11/18 10:39:56 wiz Exp $

DISTNAME=	HDF4.2r1
PKGNAME=	hdf-4.2r1
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.hdfgroup.org/HDF/prev-releases/HDF4.2r1/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hdf.ncsa.uiuc.edu/hdf4.html
COMMENT=	NCSA Hierarchical Data Format

USE_TOOLS+=		lex gmake yacc
USE_LANGUAGES=		c fortran
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/hdf
CONFIGURE_ARGS+=	--with-szlib

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

.include "../../archivers/szip/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

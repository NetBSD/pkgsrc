# $NetBSD: Makefile,v 1.33 2009/12/10 17:10:14 drochner Exp $

DISTNAME=	HDF4.2r4
PKGNAME=	hdf-4.2r4
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.hdfgroup.org/HDF/HDF_Current/src/
EXTRACT_USING=	gtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.hdfgroup.org/products/hdf4/
COMMENT=	NCSA Hierarchical Data Format

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
USE_TOOLS+=		lex gmake yacc
USE_LANGUAGES=		c fortran
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/hdf
CONFIGURE_ARGS+=	--with-szlib
# pkgsrc libtool builds shared objects anyway
#CONFIGURE_ARGS+=	--enable-shared

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

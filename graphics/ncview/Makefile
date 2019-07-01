# $NetBSD: Makefile,v 1.40 2019/07/01 04:08:23 ryoon Exp $

DISTNAME=		ncview-1.92d
PKGREVISION=	16
CATEGORIES=		graphics
MASTER_SITES=		ftp://cirrus.ucsd.edu/pub/ncview/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://meteora.ucsd.edu/~pierce/ncview_home_page.html
COMMENT=		Visual browser for netCDF format files

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-netcdf_incdir=${BUILDLINK_PREFIX.netcdf}/include
CONFIGURE_ARGS+=	--with-netcdf_libdir=${BUILDLINK_PREFIX.netcdf}/lib
CONFIGURE_ARGS+=	--with-udunits_incdir=${BUILDLINK_PREFIX.udunits}/include
CONFIGURE_ARGS+=	--with-udunits_libdir=${BUILDLINK_PREFIX.udunits}/lib

INSTALL_MAKE_FLAGS+=	BINDIR=${DESTDIR}${PREFIX}/bin \
			MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1 \
			NCVIEW_LIB_DIR=${DESTDIR}${PREFIX}/libdata/ncview

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
GCC_REQD+=		2.95.3
.endif

.include "../../devel/netcdf/buildlink3.mk"
.include "../../math/udunits/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

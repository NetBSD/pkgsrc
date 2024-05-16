# $NetBSD: Makefile,v 1.59 2024/05/16 06:15:02 wiz Exp $

DISTNAME=		ncview-2.1.7
PKGREVISION=		8
CATEGORIES=		graphics
MASTER_SITES=		ftp://cirrus.ucsd.edu/pub/ncview/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://meteora.ucsd.edu/~pierce/ncview_home_page.html
COMMENT=		Visual browser for netCDF format files
LICENSE=		gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_TOOLS=		pkg-config
CONFIG_SHELL=		bash
USE_TOOLS+=		bash

CONFIGURE_ARGS+=	--with-udunits2_incdir=${BUILDLINK_PREFIX.udunits}/include
CONFIGURE_ARGS+=	--with-udunits2_libdir=${BUILDLINK_PREFIX.udunits}/lib

INSTALLATION_DIRS+=	bin lib/X11/app-defaults libdata/ncview ${PKGMANDIR}/man1

NCMAP_FILES+=		3gauss.ncmap
NCMAP_FILES+=		3saw.ncmap
NCMAP_FILES+=		bw.ncmap
NCMAP_FILES+=		default.ncmap
NCMAP_FILES+=		detail.ncmap
NCMAP_FILES+=		hotres.ncmap

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ncview ${DESTDIR}${PREFIX}/bin/ncview
	${INSTALL_DATA} ${WRKSRC}/Ncview-appdefaults ${DESTDIR}${PREFIX}/lib/X11/app-defaults/Ncview
	${INSTALL_DATA} ${WRKSRC}/data/SciPlot.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/SciPlot.1
	${INSTALL_DATA} ${WRKSRC}/data/ncview.1.sed ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/ncview.1
.for f in ${NCMAP_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/libdata/ncview/${f}
.endfor

.include "../../devel/hdf5/buildlink3.mk"
.include "../../devel/netcdf/buildlink3.mk"
.include "../../devel/netcdf-fortran/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../math/udunits/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

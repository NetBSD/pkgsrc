# $NetBSD: Makefile,v 1.12 2009/12/15 21:48:01 joerg Exp $
#

DISTNAME=		h5utils-1.12.1
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		http://ab-initio.mit.edu/h5utils/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://ab-initio.mit.edu/h5utils/
COMMENT=		Utilities for conversion from/to HDF5

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
PKG_DESTDIR_SUPPORT=	user-destdir

pre-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/h5utils/colormaps

.include "../../devel/hdf5/buildlink3.mk"
.include "../../devel/hdf/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../math/libmatheval/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

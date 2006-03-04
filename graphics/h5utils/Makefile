# $NetBSD: Makefile,v 1.6 2006/03/04 21:29:49 jlam Exp $
#

DISTNAME=		h5utils-1.9.1
PKGREVISION=		3
CATEGORIES=		graphics
MASTER_SITES=		http://ab-initio.mit.edu/h5utils/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://ab-initio.mit.edu/h5utils/
COMMENT=		Utilities for conversion from/to HDF5

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/h5utils/colormaps

.include "../../devel/hdf5/buildlink3.mk"
.include "../../devel/hdf/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../math/libmatheval/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.5 2006/02/05 23:09:33 joerg Exp $
#

DISTNAME=		h5utils-1.9.1
PKGREVISION=		3
CATEGORIES=		graphics
MASTER_SITES=		http://ab-initio.mit.edu/h5utils/

MAINTAINER=		tech-pkg@NetBSD.org
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

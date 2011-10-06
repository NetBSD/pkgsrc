# $NetBSD: Makefile,v 1.18 2011/10/06 20:26:28 alnsn Exp $
#

DISTNAME=		h5utils-1.12.1
PKGREVISION=		4
CATEGORIES=		graphics
MASTER_SITES=		http://ab-initio.mit.edu/h5utils/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://ab-initio.mit.edu/h5utils/
COMMENT=		Utilities for conversion from/to HDF5
LICENSE=		mit AND gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-octave
PKG_DESTDIR_SUPPORT=	user-destdir

pre-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/h5utils/colormaps

.include "../../devel/hdf5/buildlink3.mk"
.include "../../devel/hdf/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../math/libmatheval/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

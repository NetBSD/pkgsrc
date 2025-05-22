# $NetBSD: Makefile,v 1.26 2025/05/22 11:27:52 wiz Exp $

DISTNAME=		h5utils-1.13.2
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_GITHUB:=NanoComp/}
GITHUB_RELEASE=		${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/NanoComp/h5utils
COMMENT=		Utilities for conversion from/to HDF5
LICENSE=		mit AND gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-octave

.include "../../devel/hdf5/buildlink3.mk"
.include "../../devel/hdf/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../math/libmatheval/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

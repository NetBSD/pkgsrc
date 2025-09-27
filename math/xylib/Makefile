# $NetBSD: Makefile,v 1.8 2025/09/27 09:57:28 wiz Exp $

PKGREVISION= 1
.include "Makefile.common"
COMMENT=		Library for reading powder diffraction data

CONFIGURE_ARGS+=	--without-gui

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

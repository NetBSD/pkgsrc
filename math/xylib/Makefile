# $NetBSD: Makefile,v 1.7 2020/01/07 13:03:50 nros Exp $

.include "Makefile.common"
COMMENT=		Library for reading powder diffraction data

CONFIGURE_ARGS+=	--without-gui

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

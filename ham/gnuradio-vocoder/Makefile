# $NetBSD: Makefile,v 1.65 2024/08/20 17:46:19 gdt Exp $

PKGNAME=	gnuradio-vocoder-${VERSION}
PKGREVISION=	4
COMMENT=	All available vocoders in GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"
.include "../../ham/gnuradio-core/Nocore.mk"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_VOCODER=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GRC=ON

PLIST_MINUS+=	companion

.include "../../devel/libusb1/buildlink3.mk"
.include "../../ham/codec2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

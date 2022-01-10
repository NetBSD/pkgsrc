# $NetBSD: Makefile,v 1.34 2022/01/10 01:46:36 ryoon Exp $

PKGNAME=	gnuradio-vocoder-${VERSION}
PKGREVISION=	1
COMMENT=	All available vocoders in GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_VOCODER=ON
CMAKE_ARGS+=	-DENABLE_GRC=ON

PLIST_MINUS+=	companion

.include	"../../devel/libusb1/buildlink3.mk"
.include	"../../ham/codec2/buildlink3.mk"

.include	"../../mk/bsd.pkg.mk"

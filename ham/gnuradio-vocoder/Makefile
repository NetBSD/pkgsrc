# $NetBSD: Makefile,v 1.3 2015/09/01 04:14:55 mef Exp $

PKGNAME=	gnuradio-vocoder-${VERSION}
COMMENT=	All available vocoders in GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_VOCODER=True

.include	"../../devel/libusb1/buildlink3.mk"

.include	"../../mk/bsd.pkg.mk"

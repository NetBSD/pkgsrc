# $NetBSD: Makefile,v 1.5 2017/01/01 16:06:22 adam Exp $

PKGNAME=	gnuradio-vocoder-${VERSION}
PKGREVISION=	2
COMMENT=	All available vocoders in GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_VOCODER=True

.include	"../../devel/libusb1/buildlink3.mk"

.include	"../../mk/bsd.pkg.mk"

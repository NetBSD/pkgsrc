# $NetBSD: Makefile,v 1.2 2015/04/17 15:53:08 adam Exp $

PKGNAME=	gnuradio-vocoder-${VERSION}
PKGREVISION=	1
COMMENT=	All available vocoders in GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_VOCODER=True

.include	"../../devel/libusb1/buildlink3.mk"

.include	"../../mk/bsd.pkg.mk"

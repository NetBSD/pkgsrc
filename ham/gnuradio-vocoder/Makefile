# $NetBSD: Makefile,v 1.17 2020/01/12 20:20:25 ryoon Exp $

PKGNAME=	gnuradio-vocoder-${VERSION}
PKGREVISION=	3
COMMENT=	All available vocoders in GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_VOCODER=True

.include	"../../devel/libusb1/buildlink3.mk"

.include	"../../mk/bsd.pkg.mk"

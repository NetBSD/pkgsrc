# $NetBSD: Makefile,v 1.18 2020/05/06 14:04:42 adam Exp $

PKGNAME=	gnuradio-vocoder-${VERSION}
PKGREVISION=	4
COMMENT=	All available vocoders in GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_VOCODER=True

.include	"../../devel/libusb1/buildlink3.mk"

.include	"../../mk/bsd.pkg.mk"

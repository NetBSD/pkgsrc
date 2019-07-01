# $NetBSD: Makefile,v 1.15 2019/07/01 04:08:25 ryoon Exp $

PKGNAME=	gnuradio-vocoder-${VERSION}
PKGREVISION=	1
COMMENT=	All available vocoders in GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_VOCODER=True

.include	"../../devel/libusb1/buildlink3.mk"

.include	"../../mk/bsd.pkg.mk"

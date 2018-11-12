# $NetBSD: Makefile,v 1.20 2018/11/12 03:52:20 ryoon Exp $

PKGNAME=	gnuradio-fcd-${VERSION}
PKGREVISION=	2
COMMENT=	FanCube support of GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_FCD=True

.include	"../../devel/libusb1/buildlink3.mk"
.include	"../../x11/wxGTK28/buildlink3.mk"

.include	"../../mk/bsd.pkg.mk"

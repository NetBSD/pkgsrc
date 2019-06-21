# $NetBSD: Makefile,v 1.23 2019/06/21 15:54:14 mef Exp $

PKGNAME=	gnuradio-fcd-${VERSION}
COMMENT=	FanCube support of GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_FCD=True

.include	"../../devel/libusb1/buildlink3.mk"
.include	"../../x11/wxGTK28/buildlink3.mk"

.include	"../../mk/bsd.pkg.mk"

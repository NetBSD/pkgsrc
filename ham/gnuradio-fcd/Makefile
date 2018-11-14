# $NetBSD: Makefile,v 1.21 2018/11/14 22:21:48 kleink Exp $

PKGNAME=	gnuradio-fcd-${VERSION}
PKGREVISION=	3
COMMENT=	FanCube support of GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_FCD=True

.include	"../../devel/libusb1/buildlink3.mk"
.include	"../../x11/wxGTK28/buildlink3.mk"

.include	"../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.4 2015/09/01 04:14:54 mef Exp $

PKGNAME=	gnuradio-dtv-${VERSION}
COMMENT=	Various digital television standards of GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_DTV=True
CMAKE_ARGS+=	-DENABLE_GR_FEC=True

PLIST_MINUS+=	fec
.include	"../../ham/gnuradio-fec/buildlink3.mk"

.include	"../../mk/bsd.pkg.mk"

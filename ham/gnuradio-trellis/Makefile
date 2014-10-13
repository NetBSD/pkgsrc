# $NetBSD: Makefile,v 1.18 2014/10/13 12:51:10 mef Exp $

PKGNAME=	gnuradio-trellis-${VERSION}
COMMENT=	Trellis-based encoding and decoding algorithms for GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_TRELLIS=True
CMAKE_ARGS+=	-DENABLE_GR_DIGITAL=True

DEPENDS+=	gnuradio-digital-[0-9]*:../../ham/gnuradio-digital
PLIST_MINUS+=	digital

.include	"../../mk/bsd.pkg.mk"

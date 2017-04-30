# $NetBSD: Makefile,v 1.10 2017/04/30 01:21:45 ryoon Exp $

PKGNAME=	gnuradio-dtv-${VERSION}
PKGREVISION=	1
COMMENT=	Various digital television standards of GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_DTV=True
CMAKE_ARGS+=	-DENABLE_GR_FEC=True

PLIST_MINUS+=	fec
.include	"../../ham/gnuradio-fec/buildlink3.mk"
.include	"../../math/gsl/buildlink3.mk"

.include	"../../mk/bsd.pkg.mk"

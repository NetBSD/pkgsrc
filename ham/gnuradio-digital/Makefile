# $NetBSD: Makefile,v 1.1 2014/10/13 12:51:09 mef Exp $

PKGNAME=	gnuradio-digital-${VERSION}
COMMENT=	Digital related algorithms for GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_DIGITAL=True

.include	"../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.15 2019/06/21 15:54:15 mef Exp $

PKGNAME=	gnuradio-digital-${VERSION}
COMMENT=	Digital related algorithms for GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"
# link to libgnuradio-fft.so.${PKGVERSON_NOREV}
.include       "../../ham/gnuradio-core/buildlink3.mk"


CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_DIGITAL=True

.include	"../../mk/bsd.pkg.mk"

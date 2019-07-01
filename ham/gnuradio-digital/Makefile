# $NetBSD: Makefile,v 1.16 2019/07/01 04:08:24 ryoon Exp $

PKGNAME=	gnuradio-digital-${VERSION}
PKGREVISION=	1
COMMENT=	Digital related algorithms for GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"
# link to libgnuradio-fft.so.${PKGVERSON_NOREV}
.include       "../../ham/gnuradio-core/buildlink3.mk"


CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_DIGITAL=True

.include	"../../mk/bsd.pkg.mk"

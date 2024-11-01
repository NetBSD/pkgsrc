# $NetBSD: Makefile,v 1.86 2024/11/01 00:52:19 wiz Exp $

PKGNAME=	gnuradio-trellis-${VERSION}
PKGREVISION=	7
COMMENT=	Trellis-based encoding and decoding algorithms for GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"
.include "../../ham/gnuradio-core/Nocore.mk"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_TRELLIS=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_DIGITAL=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GRC=ON

DEPENDS+=	gnuradio-digital-[0-9]*:../../ham/gnuradio-digital
DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

PLIST_MINUS+=	companion digital

.include "../../mk/bsd.pkg.mk"

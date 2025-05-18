# $NetBSD: Makefile,v 1.78 2025/05/18 19:31:21 gdt Exp $

PKGNAME=	gnuradio-vocoder-${VERSION}
PKGREVISION=	3
COMMENT=	All available vocoders in GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_VOCODER=ON

REPLACE_PYTHON+=	gr-vocoder/examples/*.py
REPLACE_PYTHON+=	gr-vocoder/python/vocoder/*.py

.include "../../devel/libusb1/buildlink3.mk"
.include "../../ham/codec2/buildlink3.mk"
.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

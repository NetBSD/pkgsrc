# $NetBSD: Makefile,v 1.7 2006/11/13 18:12:41 wulf Exp $

PKGNAME=	gnuradio-usrp-${VERSION}
COMMENT=	USRP bindings for GNU Radio

PYTHON_PATCH_SCRIPTS+=	gr-usrp/src/flexrf_debug_gui.py
PYTHON_PATCH_SCRIPTS+=	gr-usrp/src/qa_usrp.py
PYTHON_PATCH_SCRIPTS+=	gr-usrp/src/tx_debug_gui.py

.include "../../meta-pkgs/gnuradio/Makefile.common"

CONFIGURE_ARGS+=--enable-gr-usrp

.include "../../ham/usrp/buildlink3.mk"
.include "../../math/fftwf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

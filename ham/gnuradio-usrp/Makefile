# $NetBSD: Makefile,v 1.22 2014/01/25 10:45:19 wiz Exp $

PKGNAME=	gnuradio-usrp-${VERSION}
PKGREVISION=	8
COMMENT=	USRP bindings for GNU Radio

REPLACE_PYTHON+=	gr-usrp/src/flexrf_debug_gui.py
REPLACE_PYTHON+=	gr-usrp/src/qa_usrp.py
REPLACE_PYTHON+=	gr-usrp/src/tx_debug_gui.py

.include "../../meta-pkgs/gnuradio/Makefile.common"

CONFIGURE_ARGS+=--enable-gr-usrp
CONFIGURE_ARGS+=--with-usrp --with-gnuradio-core --with-omnithread --with-gruel

.include "../../ham/usrp/buildlink3.mk"
.include "../../math/fftwf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

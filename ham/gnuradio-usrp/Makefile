# $NetBSD: Makefile,v 1.8 2008/07/14 12:56:06 joerg Exp $

PKGNAME=	gnuradio-usrp-${VERSION}
COMMENT=	USRP bindings for GNU Radio

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_PATCH_SCRIPTS+=	gr-usrp/src/flexrf_debug_gui.py
PYTHON_PATCH_SCRIPTS+=	gr-usrp/src/qa_usrp.py
PYTHON_PATCH_SCRIPTS+=	gr-usrp/src/tx_debug_gui.py

.include "../../meta-pkgs/gnuradio/Makefile.common"

CONFIGURE_ARGS+=--enable-gr-usrp

.include "../../ham/usrp/buildlink3.mk"
.include "../../math/fftwf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

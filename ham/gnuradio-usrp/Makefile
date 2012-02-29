# $NetBSD: Makefile,v 1.15 2012/02/29 16:32:24 hans Exp $

PKGNAME=	gnuradio-usrp-${VERSION}
PKGREVISION=	3
COMMENT=	USRP bindings for GNU Radio

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_PATCH_SCRIPTS+=	gr-usrp/src/flexrf_debug_gui.py
PYTHON_PATCH_SCRIPTS+=	gr-usrp/src/qa_usrp.py
PYTHON_PATCH_SCRIPTS+=	gr-usrp/src/tx_debug_gui.py

.include "../../meta-pkgs/gnuradio/Makefile.common"

CONFIGURE_ARGS+=--enable-gr-usrp
CONFIGURE_ARGS+=--with-usrp --with-gnuradio-core --with-omnithread --with-gruel

.include "../../ham/usrp/buildlink3.mk"
.include "../../math/fftwf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

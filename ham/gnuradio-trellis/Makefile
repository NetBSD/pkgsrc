# $NetBSD: Makefile,v 1.4 2010/07/21 12:20:54 markd Exp $

PKGNAME=	gnuradio-trellis-${VERSION}
COMMENT=	Trellis-based encoding and decoding algorithms for GNU Radio

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/gnuradio/Makefile.common"

CONFIGURE_ARGS+=--enable-gr-trellis
CONFIGURE_ARGS+=--with-gnuradio-core --with-omnithread --with-gruel
CONFIGURE_ENV+=XMLTO=no

PYTHON_PATCH_SCRIPTS+=	gr-trellis/doc/make_numbered_listing.py
PYTHON_PATCH_SCRIPTS+=	gr-trellis/doc/test_tcm.py
PYTHON_PATCH_SCRIPTS+=	gr-trellis/doc/test_viterbi_equalization1.py
PYTHON_PATCH_SCRIPTS+=	gr-trellis/src/python/qa_trellis.py

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

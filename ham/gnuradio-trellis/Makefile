# $NetBSD: Makefile,v 1.17 2014/08/13 10:57:36 adam Exp $

PKGNAME=	gnuradio-trellis-${VERSION}
PKGREVISION=	11
COMMENT=	Trellis-based encoding and decoding algorithms for GNU Radio

.include "../../meta-pkgs/gnuradio/Makefile.common"

CONFIGURE_ARGS+=--enable-gr-trellis
CONFIGURE_ARGS+=--with-gnuradio-core --with-omnithread --with-gruel
CONFIGURE_ENV+=XMLTO=no

REPLACE_PYTHON+=	gr-trellis/doc/make_numbered_listing.py
REPLACE_PYTHON+=	gr-trellis/doc/test_tcm.py
REPLACE_PYTHON+=	gr-trellis/doc/test_viterbi_equalization1.py
REPLACE_PYTHON+=	gr-trellis/src/python/qa_trellis.py
REPLACE_PYTHON+=	gr-trellis/src/examples/*.py

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.16 2014/01/25 10:45:19 wiz Exp $

PKGNAME=	gnuradio-trellis-${VERSION}
PKGREVISION=	10
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

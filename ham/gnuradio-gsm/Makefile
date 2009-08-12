# $NetBSD: Makefile,v 1.8 2009/08/12 12:21:40 markd Exp $

PKGNAME=	gnuradio-gsm-${VERSION}
COMMENT=	GNU Radio GSM 06.10 13kbit/sec voice encoder/decoder

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/gnuradio/Makefile.common"

CONFIGURE_ARGS+=--enable-gr-gsm-fr-vocoder
CONFIGURE_ARGS+=--with-gnuradio-core --with-omnithread --with-gruel

PYTHON_PATCH_SCRIPTS+=	gr-gsm-fr-vocoder/src/python/encdec.py
PYTHON_PATCH_SCRIPTS+=	gr-gsm-fr-vocoder/src/python/qa_gsm_full_rate.py

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

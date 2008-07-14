# $NetBSD: Makefile,v 1.7 2008/07/14 12:56:06 joerg Exp $

PKGNAME=	gnuradio-gsm-${VERSION}
COMMENT=	GNU Radio GSM 06.10 13kbit/sec voice encoder/decoder

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/gnuradio/Makefile.common"

CONFIGURE_ARGS+=--enable-gr-gsm-fr-vocoder

PYTHON_PATCH_SCRIPTS+=	gr-gsm-fr-vocoder/src/python/encdec.py
PYTHON_PATCH_SCRIPTS+=	gr-gsm-fr-vocoder/src/python/qa_gsm_full_rate.py

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

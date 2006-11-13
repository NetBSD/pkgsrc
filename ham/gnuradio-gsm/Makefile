# $NetBSD: Makefile,v 1.6 2006/11/13 17:20:56 wulf Exp $

PKGNAME=	gnuradio-gsm-${VERSION}
COMMENT=	GNU Radio GSM 06.10 13kbit/sec voice encoder/decoder

.include "../../meta-pkgs/gnuradio/Makefile.common"

CONFIGURE_ARGS+=--enable-gr-gsm-fr-vocoder

PYTHON_PATCH_SCRIPTS+=	gr-gsm-fr-vocoder/src/python/encdec.py
PYTHON_PATCH_SCRIPTS+=	gr-gsm-fr-vocoder/src/python/qa_gsm_full_rate.py

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

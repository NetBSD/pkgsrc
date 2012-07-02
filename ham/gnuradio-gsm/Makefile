# $NetBSD: Makefile,v 1.14 2012/07/02 13:37:39 adam Exp $

PKGNAME=	gnuradio-gsm-${VERSION}
PKGREVISION=	5
COMMENT=	GNU Radio GSM 06.10 13kbit/sec voice encoder/decoder

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/gnuradio/Makefile.common"

CONFIGURE_ARGS+=--enable-gr-gsm-fr-vocoder
CONFIGURE_ARGS+=--with-gnuradio-core --with-omnithread --with-gruel

PYTHON_PATCH_SCRIPTS+=	gr-gsm-fr-vocoder/src/python/encdec.py
PYTHON_PATCH_SCRIPTS+=	gr-gsm-fr-vocoder/src/python/qa_gsm_full_rate.py

post-install:
	${MKDIR} ${DESTDIR}${PREFIX}/${PYSITELIB}/gnuradio/vocoder
	${TOUCH} ${DESTDIR}${PREFIX}/${PYSITELIB}/gnuradio/vocoder/__init__.py
	${PY_COMPILE_ALL} ${DESTDIR}${PREFIX}/${PYSITELIB}/gnuradio/vocoder
	${PY_COMPILE_O_ALL} ${DESTDIR}${PREFIX}/${PYSITELIB}/gnuradio/vocoder

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

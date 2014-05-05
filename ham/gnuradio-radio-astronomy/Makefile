# $NetBSD: Makefile,v 1.40 2014/05/05 00:48:01 ryoon Exp $

PKGNAME=	gnuradio-radio-astronomy-${VERSION}
PKGREVISION=	26
COMMENT=	GNU Radio module for radio astronomy

.include "../../meta-pkgs/gnuradio/Makefile.common"

CONFIGURE_ARGS+=--enable-gr-radio-astronomy
CONFIGURE_ARGS+=--with-gnuradio-core --with-omnithread --with-gruel

PYTHON_VERSIONED_DEPENDENCIES= ephem

REPLACE_PYTHON+=	gr-radio-astronomy/src/python/local_calibrator.py
REPLACE_PYTHON+=	gr-radio-astronomy/src/python/qa_ra.py
REPLACE_PYTHON+=	gr-radio-astronomy/src/python/ra_fftsink.py
REPLACE_PYTHON+=	gr-radio-astronomy/src/python/ra_stripchartsink.py
REPLACE_PYTHON+=	gr-radio-astronomy/src/python/usrp_psr_receiver.py
REPLACE_PYTHON+=	gr-radio-astronomy/src/python/usrp_ra_receiver.py

.include "../../mk/oss.buildlink3.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../ham/gnuradio-wxgui/buildlink3.mk"
.include "../../ham/usrp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

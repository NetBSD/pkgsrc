# $NetBSD: Makefile,v 1.39 2014/01/25 10:45:19 wiz Exp $

PKGNAME=	gnuradio-radio-astronomy-${VERSION}
PKGREVISION=	25
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

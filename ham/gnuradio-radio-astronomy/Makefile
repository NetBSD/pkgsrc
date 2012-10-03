# $NetBSD: Makefile,v 1.26 2012/10/03 13:01:44 asau Exp $

PKGNAME=	gnuradio-radio-astronomy-${VERSION}
PKGREVISION=	14
COMMENT=	GNU Radio module for radio astronomy

.include "../../meta-pkgs/gnuradio/Makefile.common"

CONFIGURE_ARGS+=--enable-gr-radio-astronomy
CONFIGURE_ARGS+=--with-gnuradio-core --with-omnithread --with-gruel

DEPENDS+=	${PYPKGPREFIX}-ephem>=3.7b:../../math/py-ephem

PYTHON_PATCH_SCRIPTS+=	gr-radio-astronomy/src/python/local_calibrator.py
PYTHON_PATCH_SCRIPTS+=	gr-radio-astronomy/src/python/qa_ra.py
PYTHON_PATCH_SCRIPTS+=	gr-radio-astronomy/src/python/ra_fftsink.py
PYTHON_PATCH_SCRIPTS+=	gr-radio-astronomy/src/python/ra_stripchartsink.py
PYTHON_PATCH_SCRIPTS+=	gr-radio-astronomy/src/python/usrp_psr_receiver.py
PYTHON_PATCH_SCRIPTS+=	gr-radio-astronomy/src/python/usrp_ra_receiver.py

.include "../../mk/oss.buildlink3.mk"
.include "../../ham/gnuradio-wxgui/buildlink3.mk"
.include "../../ham/usrp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

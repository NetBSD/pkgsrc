# $NetBSD: Makefile,v 1.11 2006/11/24 14:25:36 wulf Exp $

PKGNAME=	gnuradio-wxgui-${VERSION}
COMMENT=	GUI framework for GNU Radio based on wxPython

PYTHON_PATCH_SCRIPTS+=	gr-wxgui/src/python/fftsink.py
PYTHON_PATCH_SCRIPTS+=	gr-wxgui/src/python/form.py
PYTHON_PATCH_SCRIPTS+=	gr-wxgui/src/python/powermate.py
PYTHON_PATCH_SCRIPTS+=	gr-wxgui/src/python/scopesink.py
PYTHON_PATCH_SCRIPTS+=	gr-wxgui/src/python/slider.py
PYTHON_PATCH_SCRIPTS+=	gr-wxgui/src/python/waterfallsink.py

SUBST_CLASSES+=		py-exec
SUBST_STAGE.py-exec=	pre-configure
SUBST_MESSAGE.py-exec=	Fixing python exec name
SUBST_FILES.py-exec=	configure
SUBST_SED.py-exec=	-e 's,python -c,${PYTHONBIN} -c,g'

.include "../../meta-pkgs/gnuradio/Makefile.common"

CONF_FILES+=    ${EGDIR}/gr-wxgui.conf ${PKG_SYSCONFDIR}/gr-wxgui.conf
CONFIGURE_ARGS+=--enable-gr-wxgui

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../x11/py-wxWidgets/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

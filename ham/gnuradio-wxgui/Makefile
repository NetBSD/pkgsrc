# $NetBSD: Makefile,v 1.52 2014/08/13 10:57:32 adam Exp $

PKGNAME=	gnuradio-wxgui-${VERSION}
PKGREVISION=	29
COMMENT=	GUI framework for GNU Radio based on wxPython

REPLACE_PYTHON+=	gr-wxgui/src/python/form.py
REPLACE_PYTHON+=	gr-wxgui/src/python/powermate.py
REPLACE_PYTHON+=	gr-wxgui/src/python/slider.py

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-wxWidgets

SUBST_CLASSES+=		py-exec
SUBST_STAGE.py-exec=	pre-configure
SUBST_MESSAGE.py-exec=	Fixing python exec name
SUBST_FILES.py-exec=	configure
SUBST_SED.py-exec=	-e 's,python -c,${PYTHONBIN} -c,g'

.include "../../meta-pkgs/gnuradio/Makefile.common"

CONF_FILES+=	${EGDIR}/gr-wxgui.conf ${PKG_SYSCONFDIR}/gr-wxgui.conf
CONFIGURE_ARGS+=--enable-gr-wxgui
CONFIGURE_ARGS+=--with-gnuradio-core --with-omnithread --with-gruel

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../x11/py-wxWidgets/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

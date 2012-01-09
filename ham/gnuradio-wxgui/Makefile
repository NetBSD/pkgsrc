# $NetBSD: Makefile,v 1.26 2012/01/09 02:54:25 obache Exp $

PKGNAME=	gnuradio-wxgui-${VERSION}
PKGREVISION=	6
COMMENT=	GUI framework for GNU Radio based on wxPython

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_PATCH_SCRIPTS+=	gr-wxgui/src/python/form.py
PYTHON_PATCH_SCRIPTS+=	gr-wxgui/src/python/powermate.py
PYTHON_PATCH_SCRIPTS+=	gr-wxgui/src/python/slider.py

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

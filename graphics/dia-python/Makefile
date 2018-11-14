# $NetBSD: Makefile,v 1.55 2018/11/14 22:21:36 kleink Exp $

DIA_SUBPKG=		-python
PKGREVISION= 7
.include "../../graphics/dia/Makefile.common"

COMMENT+=		(Python plugin)

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/--without-python/--with-python/g}
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}

REPLACE_PYTHON=	po-checktrans.py
REPLACE_PYTHON+=	plug-ins/python/gtkcons.py
REPLACE_PYTHON+=	sheets/checktrans.py
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-gtk2

BUILD_DIRS+=		plug-ins/python
INSTALL_DIRS+=		plug-ins/python

post-install:
	${PY_COMPILE_ALL} ${DESTDIR}${PREFIX}/share/dia

.include "../../lang/python/application.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

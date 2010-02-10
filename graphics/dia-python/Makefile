# $NetBSD: Makefile,v 1.15 2010/02/10 19:17:39 joerg Exp $
#
PKGREVISION=	1

DIA_SUBPKG=		-python
.include "../../graphics/dia/Makefile.common"

COMMENT+=		(Python plugin)

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/--without-python/--with-python/g}
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}

PYTHON_PATCH_SCRIPTS=	po-checktrans.py
PYTHON_PATCH_SCRIPTS+=	plug-ins/python/gtkcons.py
PYTHON_PATCH_SCRIPTS+=	sheets/checktrans.py

BUILD_DIRS+=		${WRKSRC}/plug-ins/python
INSTALL_DIRS+=		${WRKSRC}/plug-ins/python

post-install:
	${PY_COMPILE_ALL} ${DESTDIR}${PREFIX}/share/dia

.include "../../lang/python/application.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

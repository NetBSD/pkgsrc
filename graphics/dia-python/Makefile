# $NetBSD: Makefile,v 1.5 2006/02/05 23:09:29 joerg Exp $
#

DIA_SUBPKG=		-python
.include "../../graphics/dia/Makefile.common"
PKGREVISION=		3

COMMENT+=		(Python plugin)

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/--without-python/--with-python/g}
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}

PYTHON_PATCH_SCRIPTS=	po-checktrans.py
PYTHON_PATCH_SCRIPTS+=	plug-ins/python/gtkcons.py
PYTHON_PATCH_SCRIPTS+=	sheets/checktrans.py

BUILD_DIRS+=		${WRKSRC}/plug-ins/python
INSTALL_DIRS+=		${WRKSRC}/plug-ins/python

.include "../../lang/python/application.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

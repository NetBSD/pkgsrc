# $NetBSD: Makefile,v 1.4 2006/01/24 07:32:11 wiz Exp $
#

DIA_SUBPKG=		-python
.include "../../graphics/dia/Makefile.common"
PKGREVISION=		2

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

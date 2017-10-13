# $NetBSD: buildtools.mk,v 1.1 2017/10/13 15:40:12 prlw1 Exp $

TOOL_DEPENDS+=	${PYPKGPREFIX}-glib2-tools-[0-9]*:../../devel/py-glib2-tools
PYTHON_FOR_BUILD_ONLY=yes
.include "../../lang/python/pyversion.mk"

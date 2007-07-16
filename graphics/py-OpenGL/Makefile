# $NetBSD: Makefile,v 1.2 2007/07/16 15:09:40 joerg Exp $
#

DISTNAME=	PyOpenGL-3.0.0a6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^Py//}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyopengl/}

MAINTAINER=	cube@cubidou.net
HOMEPAGE=	http://pyopengl.sourceforge.net/
COMMENT=	Pyhton bindings for OpenGL

PYTHON_VERSIONS_ACCEPTED= 24
PYDISTUTILSPKG=	YES
PY_PATCHPLIST=	YES

DEPENDS+=	${PYPKGPREFIX}-setuptools>=0.6c1nb1:../../devel/py-setuptools

.include "../../lang/python/extension.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../devel/py-ctypes/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

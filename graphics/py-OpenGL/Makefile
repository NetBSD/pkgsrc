# $NetBSD: Makefile,v 1.5 2009/12/16 20:45:20 drochner Exp $
#

DISTNAME=	PyOpenGL-3.0.1b1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^Py//}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyopengl/}

MAINTAINER=	cube@cubidou.net
HOMEPAGE=	http://pyopengl.sourceforge.net/
COMMENT=	Pyhton bindings for OpenGL

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes
#PY_PATCHPLIST=	YES

# XXX devel/py-ctypes doesn't work, Python-2.5's builtin ctypes is OK
PYTHON_VERSIONS_ACCEPTED= 25

#.include "../../lang/python/egg.mk"
.include "../../lang/python/extension.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
# XXX see above
#.include "../../devel/py-ctypes/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

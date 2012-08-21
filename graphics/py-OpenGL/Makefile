# $NetBSD: Makefile,v 1.10 2012/08/21 23:49:22 marino Exp $
#

DISTNAME=	PyOpenGL-3.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^Py//}
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyopengl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pyopengl.sourceforge.net/
COMMENT=	Pyhton bindings for OpenGL

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes
#PY_PATCHPLIST=	YES

#.include "../../lang/python/egg.mk"
.include "../../lang/python/extension.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

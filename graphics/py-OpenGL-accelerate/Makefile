# $NetBSD: Makefile,v 1.2 2020/10/12 21:52:00 bacon Exp $

DISTNAME=	PyOpenGL-accelerate-3.1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^Py//}
PKGREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyOpenGL-accelerate/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pyopengl.sourceforge.net/
COMMENT=	Acceleration code for PyOpenGL
# There are many similar licenses, see license.txt
LICENSE=	modified-bsd AND mit

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

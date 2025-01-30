# $NetBSD: Makefile,v 1.13 2025/01/30 20:26:52 wiz Exp $

DISTNAME=	PyOpenGL-accelerate-3.1.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^Py//}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyOpenGL-accelerate/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pyopengl.sourceforge.net/
COMMENT=	Acceleration code for PyOpenGL
# There are many similar licenses, see license.txt
LICENSE=	modified-bsd AND mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython

zz-pre-build:
	cd ${WRKSRC}/src && for i in *.pyx; do cython-${PYVERSSUFFIX} $$i; done

# https://sourceforge.net/p/pyopengl/mailman/message/58796603/
BROKEN=		"Does not support py-numpy 2.x"

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.1 2017/11/22 11:14:52 markd Exp $

DISTNAME=	scikit-image-0.13.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scikit-image/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://scikit-image.org
COMMENT=	Image processing routines for SciPy
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-Pillow>=2.9.0:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-networkx>=1.9:../../math/py-networkx
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.15.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-PyWavelets>=0.5.2:../../math/py-pywavelets

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} skivi skivi${PYVERSSUFFIX} || ${TRUE}

.include "../../devel/py-cython/buildlink3.mk"
.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.3 2021/12/30 13:05:35 adam Exp $

DISTNAME=	Keras_Applications-1.0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=K/Keras_Applications/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/keras-team/keras-applications
COMMENT=	Reference implementations of popular deep learning models
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-h5py-[0-9]*:../../devel/py-h5py
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.9.1:../../math/py-numpy

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-h5py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

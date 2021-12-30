# $NetBSD: Makefile,v 1.3 2021/12/30 13:05:35 adam Exp $

DISTNAME=	Keras_Preprocessing-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=K/Keras_Preprocessing/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/keras-team/keras-preprocessing
COMMENT=	Data preprocessing and augmentation for deep learning models
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-numpy>=1.9.1:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.9 2025/07/03 19:18:07 wiz Exp $

DISTNAME=	Keras_Preprocessing-1.1.2
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

PYTHON_VERSIONS_INCOMPATIBLE=	39 310

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.7 2023/08/01 23:20:45 wiz Exp $

DISTNAME=	Keras_Applications-1.0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=K/Keras_Applications/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/keras-team/keras-applications
COMMENT=	Reference implementations of popular deep learning models
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-h5py-[0-9]*:../../devel/py-h5py
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.9.1:../../math/py-numpy

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

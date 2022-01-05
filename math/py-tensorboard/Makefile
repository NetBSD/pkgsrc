# $NetBSD: Makefile,v 1.6 2022/01/05 15:41:15 wiz Exp $

DISTNAME=	tensorboard-${GITHUB_TAG:S/-//}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_GITHUB:=tensorflow/}
GITHUB_PROJECT=	tensorboard
GITHUB_TAG=	1.7.0

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/tensorflow/tensorboard
COMMENT=	Web applications for inspecting TensorFlow runs and graphs
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-bleach>=1.5.0:../../www/py-bleach
DEPENDS+=	${PYPKGPREFIX}-markdown>=2.6.8:../../textproc/py-markdown
DEPENDS+=	${PYPKGPREFIX}-html5lib>=0.9999999:../../textproc/py-html5lib
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.12.0:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-protobuf>=3.3.0:../../devel/py-protobuf
DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-werkzeug>=0.11.10:../../www/py-werkzeug

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-protobuf, py-numpy

USE_PKG_RESOURCES=	yes

post-extract:
.for f in MANIFEST.in setup.cfg setup.py
	${CP} ${WRKSRC}/tensorboard/pip_package/${f} ${WRKSRC}
.endfor

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} tensorboard tensorboard${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

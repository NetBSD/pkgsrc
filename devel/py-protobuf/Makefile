# $NetBSD: Makefile,v 1.9 2016/10/19 12:16:34 wiz Exp $

.include "../../devel/protobuf/Makefile.common"

DISTNAME=	protobuf-python-${PROTOBUFVER}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-python//}
CATEGORIES+=	python

MAINTAINER=	khorben@defora.org
COMMENT=	Python bindings for protobuf

PYSETUPSUBDIR=	python

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # py-gflags

BUILD_DEPENDS+=	${PYPKGPREFIX}-gflags-[0-9]*:../../devel/py-gflags
BUILD_DEPENDS+=	${PYPKGPREFIX}-google-apputils-[0-9]*:../../devel/py-google-apputils
BUILD_DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
BUILD_DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz

EGG_NAME=	protobuf-${PKGVERSION_NOREV}

.include "../../devel/protobuf/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

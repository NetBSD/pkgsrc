# $NetBSD: Makefile,v 1.5 2015/06/24 18:09:59 khorben Exp $

.include "../../devel/protobuf/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://code.google.com/p/protobuf/
COMMENT=	Google protocol buffers
LICENSE=	modified-bsd

PYSETUPSUBDIR=	python

PYTHON_VERSIONS_INCOMPATIBLE=	33 34

BUILD_DEPENDS+=	${PYPKGPREFIX}-gflags-[0-9]*:../../devel/py-gflags
BUILD_DEPENDS+=	${PYPKGPREFIX}-google-apputils-[0-9]*:../../devel/py-google-apputils
BUILD_DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
BUILD_DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz

.include "../../devel/protobuf/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.33 2020/11/14 14:08:16 adam Exp $

DISTNAME=	protobuf-3.14.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-python//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/protobuf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developers.google.com/protocol-buffers/
COMMENT=	Python bindings for protobuf
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-pip-[0-9]*:../../devel/py-pip
DEPENDS+=	${PYPKGPREFIX}-six>=1.9:../../lang/py-six
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0.32.0:../../devel/py-wheel

USE_LANGUAGES+=	c c++11

PYTHON_VERSIONED_DEPENDENCIES+=	setuptools

MAKE_ENV+=		PROTOC=${PREFIX}/bin/protoc
PYSETUPBUILDARGS=	--cpp_implementation
PYSETUPINSTALLARGS=	--cpp_implementation

.include "../../devel/protobuf/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"

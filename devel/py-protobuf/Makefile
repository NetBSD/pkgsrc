# $NetBSD: Makefile,v 1.16 2019/01/08 05:56:19 markd Exp $

.include "../../devel/protobuf/Makefile.common"

DISTNAME=	protobuf-python-${PROTOBUFVER}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-python//}
CATEGORIES+=	python

MAINTAINER=	khorben@defora.org
COMMENT=	Python bindings for protobuf

USE_LANGUAGES+=	c c++11
CFLAGS+=	-std=c++11	# NetBSD complains without this

PYSETUPSUBDIR=	python
PYSETUPBUILDARGS=	--cpp_implementation
PYSETUPINSTALLARGS=	--cpp_implementation

DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython
DEPENDS+=	${PYPKGPREFIX}-six>=1.9:../../lang/py-six

EGG_NAME=	protobuf-${PKGVERSION_NOREV}

.include "../../devel/protobuf/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

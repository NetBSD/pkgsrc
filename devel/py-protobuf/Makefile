# $NetBSD: Makefile,v 1.14 2018/08/04 21:32:53 minskim Exp $

.include "../../devel/protobuf/Makefile.common"

DISTNAME=	protobuf-python-${PROTOBUFVER}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-python//}
CATEGORIES+=	python

MAINTAINER=	khorben@defora.org
COMMENT=	Python bindings for protobuf

PYSETUPSUBDIR=	python

DEPENDS+=	${PYPKGPREFIX}-six>=1.9:../../lang/py-six

EGG_NAME=	protobuf-${PKGVERSION_NOREV}

.include "../../devel/protobuf/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

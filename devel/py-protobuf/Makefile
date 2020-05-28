# $NetBSD: Makefile,v 1.28 2020/05/28 11:52:13 adam Exp $

DISTNAME=	protobuf-python-3.12.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-python//}
CATEGORIES=	devel python
#MASTER_SITES=	${MASTER_SITE_PYPI:=p/protobuf/}
MASTER_SITES=	${MASTER_SITE_GITHUB:=protocolbuffers/}
GITHUB_PROJECT=	protobuf
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developers.google.com/protocol-buffers/
COMMENT=	Python bindings for protobuf
LICENSE=	modified-bsd

EGG_NAME=	${DISTNAME:S/-python//}
WRKSRC=		${WRKDIR}/${DISTNAME:S/-python//}/python

DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-six>=1.9:../../lang/py-six

USE_LANGUAGES+=	c c++11

MAKE_ENV+=		PROTOC=${PREFIX}/bin/protoc
PYSETUPBUILDARGS=	--cpp_implementation
PYSETUPINSTALLARGS=	--cpp_implementation

.include "../../devel/protobuf/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

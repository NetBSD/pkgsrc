# $NetBSD: Makefile,v 1.36 2022/07/02 09:31:44 adam Exp $

DISTNAME=	pyzmq-23.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyzmq/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zeromq/pyzmq
COMMENT=	Python bindings for zeromq
LICENSE=	gnu-lgpl-v3 AND modified-bsd

DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_TOOLS+=	pkg-config

PYTHON_VERSIONS_INCOMPATIBLE=	27

PYSETUPBUILDARGS+=	--zmq=${BUILDLINK_PREFIX.zeromq:Q}

.include "../../lang/python/egg.mk"
.include "../../net/zeromq/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

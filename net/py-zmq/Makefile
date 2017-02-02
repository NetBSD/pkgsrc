# $NetBSD: Makefile,v 1.18 2017/02/02 10:16:30 fhajny Exp $

DISTNAME=	pyzmq-16.0.2
PKGNAME=        ${DISTNAME:S/py/${PYPKGPREFIX}-/1}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyzmq/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zeromq/pyzmq/
COMMENT=	Python bindings for zeromq
LICENSE=	gnu-lgpl-v3 AND modified-bsd

PYSETUPBUILDARGS+=	--zmq=${BUILDLINK_PREFIX.zeromq:Q}
REPLACE_PYTHON+=	zmq/eventloop/minitornado/ioloop.py
REPLACE_PYTHON+=	zmq/eventloop/minitornado/platform/auto.py
REPLACE_PYTHON+=	zmq/eventloop/minitornado/platform/interface.py
REPLACE_PYTHON+=	zmq/eventloop/minitornado/platform/posix.py
REPLACE_PYTHON+=	zmq/eventloop/minitornado/stack_context.py

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../net/zeromq/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

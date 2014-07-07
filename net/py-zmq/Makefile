# $NetBSD: Makefile,v 1.15 2014/07/07 13:05:35 obache Exp $

DISTNAME=	pyzmq-14.3.0
PKGNAME=        ${DISTNAME:S/py/${PYPKGPREFIX}-/1}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	https://pypi.python.org/packages/source/p/pyzmq/

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

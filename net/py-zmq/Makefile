# $NetBSD: Makefile,v 1.12 2014/01/25 10:30:17 wiz Exp $

DISTNAME=	pyzmq-13.1.0
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	net
MASTER_SITES=	http://cloud.github.com/downloads/zeromq/pyzmq/	\
		http://pypi.python.org/packages/source/p/pyzmq/

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

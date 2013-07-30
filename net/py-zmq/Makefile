# $NetBSD: Makefile,v 1.9 2013/07/30 01:27:37 obache Exp $
#

DISTNAME=	pyzmq-2.2.0.1
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://cloud.github.com/downloads/zeromq/pyzmq/	\
		http://pypi.python.org/packages/source/p/pyzmq/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zeromq/pyzmq/
COMMENT=	Python bindings for zeromq
LICENSE=	gnu-lgpl-v3 AND modified-bsd

PYSETUPBUILDARGS+=	 --zmq=${BUILDLINK_PREFIX.zeromq:Q}

.include "../../lang/python/distutils.mk"
.include "../../net/zeromq/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

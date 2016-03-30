# $NetBSD: Makefile,v 1.3 2016/03/30 13:25:41 wiz Exp $

DISTNAME=	thrift-0.9.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=t/thrift/}

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://pypi.python.org/pypi/thrift
COMMENT=	Python bindings for the Apache Thrift RPC system
LICENSE=	apache-2.0

PYTHON_VERSIONS_ACCEPTED=	27 # uses cStringio.h header

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

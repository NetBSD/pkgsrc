# $NetBSD: Makefile,v 1.11 2016/04/21 09:31:21 fhajny Exp $

DISTNAME=	python-driver-3.2.2
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}-cassandra/}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=datastax/}
GITHUB_PROJECT=	python-driver

MAINTAINER=	filip@joyent.com
HOMEPAGE=	https://github.com/datastax/python-driver/
COMMENT=	DataStax Python Driver for Apache Cassandra
LICENSE=	apache-2.0

EGG_NAME=	cassandra_driver-${PKGVERSION_NOREV}

.include "../../lang/python/pyversion.mk"

DEPENDS+=	${PYPKGPREFIX}-cython>=0.20:../../devel/py-cython
DEPENDS+=	${PYPKGPREFIX}-six>=1.6:../../lang/py-six
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-futures-[0-9]*:../../devel/py-futures
.endif

.include "../../devel/libev/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

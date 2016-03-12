# $NetBSD: Makefile,v 1.7 2016/03/12 09:53:53 fhajny Exp $

DISTNAME=	python-driver-3.1.0
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}-cassandra/}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=datastax/}
GITHUB_PROJECT=	python-driver

MAINTAINER=	filip@joyent.com
HOMEPAGE=	https://github.com/datastax/python-driver/
COMMENT=	DataStax Python Driver for Apache Cassandra
LICENSE=	apache-2.0

EGG_NAME=	cassandra_driver-${PKGVERSION_NOREV}

DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython

.include "../../devel/libev/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

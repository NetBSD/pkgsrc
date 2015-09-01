# $NetBSD: Makefile,v 1.4 2015/09/01 11:51:00 fhajny Exp $

DISTNAME=	python-driver-2.7.1
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}-cassandra/}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=datastax/}
GITHUB_PROJECT=	python-driver

MAINTAINER=	filip@joyent.com
HOMEPAGE=	https://github.com/datastax/python-driver/
COMMENT=	DataStax Python Driver for Apache Cassandra
LICENSE=	apache-2.0

EGG_NAME=	cassandra_driver-${PKGVERSION_NOREV}

.include "../../devel/libev/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

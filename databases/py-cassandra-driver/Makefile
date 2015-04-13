# $NetBSD: Makefile,v 1.2 2015/04/13 12:44:07 fhajny Exp $

DISTNAME=	python-driver-2.5.0
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}-cassandra/}
CATEGORIES=	databases
MASTER_SITES=	-https://github.com/datastax/python-driver/archive/${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=	filip@joyent.com
HOMEPAGE=	https://github.com/datastax/python-driver/
COMMENT=	DataStax Python Driver for Apache Cassandra
LICENSE=	apache-2.0

EGG_NAME=	cassandra_driver-${PKGVERSION_NOREV}

.include "../../devel/libev/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

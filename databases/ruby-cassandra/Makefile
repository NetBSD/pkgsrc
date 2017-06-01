# $NetBSD: Makefile,v 1.13 2017/06/01 04:41:05 taca Exp $

DISTNAME=	cassandra-0.23.0
PKGREVISION=	1
CATEGORIES=	databases ruby

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cassandra-rb/cassandra/
COMMENT=	Ruby extension for Cassandra
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-simple_uuid>=0.3<1:../../devel/ruby-simple_uuid
DEPENDS+=	${RUBY_PKGPREFIX}-thrift_client<0.9:../../devel/ruby-thrift_client

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

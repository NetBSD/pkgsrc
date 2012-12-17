# $NetBSD: Makefile,v 1.9 2012/12/17 12:29:00 taca Exp $

DISTNAME=	cassandra-0.17.0
CATEGORIES=	databases ruby

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://blog.evanweaver.com/files/doc/fauna/cassandra/
COMMENT=	Ruby extension for Cassandra
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-simple_uuid>=0.2<1:../../devel/ruby-simple_uuid
DEPENDS+=	${RUBY_PKGPREFIX}-thrift_client<0.9:../../devel/ruby-thrift_client

RUBY_JSON_REQD=	0
USE_RAKE=	run
OVERRIDE_GEMSPEC=	simple_uuid~>0.2

.include "../../lang/ruby/gem.mk"
.include "../../lang/ruby/json.mk"
.include "../../mk/bsd.pkg.mk"

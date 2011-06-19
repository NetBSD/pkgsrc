# $NetBSD: Makefile,v 1.3 2011/06/19 08:41:57 taca Exp $

DISTNAME=	cassandra-0.11.1
CATEGORIES=	databases ruby

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://blog.evanweaver.com/files/doc/fauna/cassandra/
COMMENT=	Ruby extension for Cassandra
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-simple_uuid>=0.1.0:../../devel/ruby-simple_uuid
DEPENDS+=	${RUBY_PKGPREFIX}-json>=0:../../textproc/ruby-json
DEPENDS+=	${RUBY_PKGPREFIX}-thrift_client>=0.6.0:../../devel/ruby-thrift_client

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

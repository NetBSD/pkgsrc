# $NetBSD: Makefile,v 1.2 2010/09/10 04:14:08 taca Exp $

DISTNAME=	cassandra-0.8.2
CATEGORIES=	databases ruby

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://blog.evanweaver.com/files/doc/fauna/cassandra/
COMMENT=	Ruby extension for Cassandra
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-simple_uuid>=0.1.0:../../devel/ruby-simple_uuid
DEPENDS+=	${RUBY_PKGPREFIX}-json>=0:../../textproc/ruby-json
DEPENDS+=	${RUBY_PKGPREFIX}-thrift_client>=0.4.0:../../devel/ruby-thrift_client

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

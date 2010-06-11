# $NetBSD: Makefile,v 1.1.1.1 2010/06/11 23:41:15 tonnerre Exp $

DISTNAME=	activerecord-cassandra-adapter-0.1.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/-adapter//}
CATEGORIES=	databases

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://github.com/winebarrel/activerecord-cassandra-adapter
COMMENT=	ActiveRecord Cassandra adapter

DEPENDS+=	${RUBY_PKGPREFIX}-activerecord>=2.0.2:../../databases/ruby-activerecord
DEPENDS+=	${RUBY_PKGPREFIX}-cassandra>=0:../../databases/ruby-cassandra

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"

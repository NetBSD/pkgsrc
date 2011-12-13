# $NetBSD: Makefile,v 1.5 2011/12/13 15:48:55 taca Exp $

DISTNAME=	activerecord-cassandra-adapter-0.1.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/-adapter//}
CATEGORIES=	databases

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://github.com/winebarrel/activerecord-cassandra-adapter
COMMENT=	ActiveRecord Cassandra adapter

DEPENDS+=	${RUBY_ACTIVERECORD_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-cassandra>=0:../../databases/ruby-cassandra

RUBY_RAILS_SUPPORTED=	# defined

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

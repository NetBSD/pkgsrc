# $NetBSD: Makefile,v 1.7 2017/06/21 15:42:10 taca Exp $

DISTNAME=	activerecord-cassandra-adapter-0.1.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/-adapter//}
PKGREVISION=	1
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/winebarrel/activerecord-cassandra-adapter
COMMENT=	ActiveRecord Cassandra adapter

DEPENDS+=	${RUBY_ACTIVERECORD_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-cassandra>=0:../../databases/ruby-cassandra

RUBY_RAILS_SUPPORTED=	# defined

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

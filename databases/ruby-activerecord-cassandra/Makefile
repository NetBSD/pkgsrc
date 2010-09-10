# $NetBSD: Makefile,v 1.2 2010/09/10 04:11:12 taca Exp $

DISTNAME=	activerecord-cassandra-adapter-0.1.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/-adapter//}
CATEGORIES=	databases

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://github.com/winebarrel/activerecord-cassandra-adapter
COMMENT=	ActiveRecord Cassandra adapter
LICENSE=	# unknown

DEPENDS+=	${RUBY_PKGPREFIX}-activerecord>=2.0.2:../../databases/ruby-activerecord
DEPENDS+=	${RUBY_PKGPREFIX}-cassandra>=0:../../databases/ruby-cassandra

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

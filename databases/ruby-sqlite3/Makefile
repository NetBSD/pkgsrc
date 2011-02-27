# $NetBSD: Makefile,v 1.14.2.1 2011/02/27 00:26:14 tron Exp $

DISTNAME=	sqlite3-ruby-1.3.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/-ruby//}
PKGREVISION=	1
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/luislavena/sqlite3-ruby
COMMENT=	Ruby interface for the SQLite database engine
LICENSE=	modified-bsd

.include "../../lang/ruby/gem.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.12 2010/07/10 09:29:21 obache Exp $

DISTNAME=	sqlite3-ruby-1.3.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/-ruby//}
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sqlite-ruby.rubyforge.org/
COMMENT=	Ruby interface for the SQLite database engine
LICENSE=	modified-bsd

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

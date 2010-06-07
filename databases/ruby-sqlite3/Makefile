# $NetBSD: Makefile,v 1.11 2010/06/07 09:34:41 obache Exp $

DISTNAME=	sqlite3-ruby-1.3.0
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

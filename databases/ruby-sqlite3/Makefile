# $NetBSD: Makefile,v 1.8 2008/06/22 15:52:59 taca Exp $

DISTNAME=	sqlite3-ruby-1.2.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/-ruby//}
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sqlite-ruby.rubyforge.org/
COMMENT=	Ruby interface for the SQLite database engine

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

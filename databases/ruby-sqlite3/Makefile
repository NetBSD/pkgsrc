# $NetBSD: Makefile,v 1.7 2008/04/10 07:28:50 obache Exp $

DISTNAME=	sqlite3-ruby-1.2.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/-ruby//}
PKGREVISION=	1
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sqlite-ruby.rubyforge.org/
COMMENT=	Ruby interface for the SQLite database engine

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

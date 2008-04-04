# $NetBSD: Makefile,v 1.6 2008/04/04 15:30:00 jlam Exp $

DISTNAME=	sqlite3-ruby-1.2.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/-ruby//}
PKGREVISION=	1
CATEGORIES=	databases

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://sqlite-ruby.rubyforge.org/
COMMENT=	Ruby interface for the SQLite database engine

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

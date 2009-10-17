# $NetBSD: Makefile,v 1.1.1.1 2009/10/17 12:24:46 taca Exp $

DISTNAME=	sqlite-ruby-2.2.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/-ruby//}
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sqlite-ruby.rubyforge.org/
COMMENT=	Ruby interface for the SQLite database engine

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../databases/sqlite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

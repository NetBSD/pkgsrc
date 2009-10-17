# $NetBSD: Makefile,v 1.1.1.1 2009/10/17 12:32:39 taca Exp $

DISTNAME=	dbd-sqlite3-1.2.5
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	databases ruby

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/ruby-dbi/
COMMENT=	SQLite version 3 support for Ruby/DBI
LICENSE=	modified-bsd

DEPENDS=	${RUBY_PKGPREFIX}-dbi>=0.4.3:../../databases/ruby-dbi
DEPENDS=	${RUBY_PKGPREFIX}-sqlite3>=1.2.4:../../databases/ruby-sqlite3

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"

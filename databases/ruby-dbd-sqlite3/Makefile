# $NetBSD: Makefile,v 1.4 2015/09/25 05:47:36 taca Exp $

DISTNAME=	dbd-sqlite3-1.2.5
PKGREVISION=	1
CATEGORIES=	databases ruby

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	# http://rubyforge.org/projects/ruby-dbi/
COMMENT=	SQLite version 3 support for Ruby/DBI
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-dbi>=0.4.3:../../databases/ruby-dbi
DEPENDS+=	${RUBY_PKGPREFIX}-sqlite3>=1.2.4:../../databases/ruby-sqlite3

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

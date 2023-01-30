# $NetBSD: Makefile,v 1.6 2023/01/30 13:41:00 taca Exp $

DISTNAME=	dbd-sqlite-0.1.2
PKGREVISION=	1
CATEGORIES=	databases ruby

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	# http://rubyforge.org/projects/ruby-dbi/
COMMENT=	SQLite support for Ruby/DBI
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-dbi>=0.4.3:../../databases/ruby-dbi
DEPENDS+=	${RUBY_PKGPREFIX}-sqlite>=2.2.3:../../databases/ruby-sqlite

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

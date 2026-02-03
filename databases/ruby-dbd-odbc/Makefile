# $NetBSD: Makefile,v 1.5 2026/02/03 16:04:39 taca Exp $

DISTNAME=	dbd-odbc-0.2.5
PKGREVISION=	1
CATEGORIES=	databases ruby

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	# http://rubyforge.org/projects/ruby-dbi/
COMMENT=	ODBC support for Ruby/DBI
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-dbi>=0.4.3:../../databases/ruby-dbi
DEPENDS+=	${RUBY_PKGPREFIX}-odbc>=0.9995:../../databases/ruby-odbc

RUBY_ALLOW_HAS_RDOC=	# empty

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

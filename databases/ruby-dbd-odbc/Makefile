# $NetBSD: Makefile,v 1.1.1.1 2009/10/17 12:33:41 taca Exp $

DISTNAME=	dbd-odbc-0.2.5
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	databases ruby

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/ruby-dbi/
COMMENT=	ODBC support for Ruby/DBI
LICENSE=	modified-bsd

DEPENDS=	${RUBY_PKGPREFIX}-dbi>=0.4.3:../../databases/ruby-dbi
DEPENDS=	${RUBY_PKGPREFIX}-odbc>=0.9995:../../databases/ruby-odbc

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"

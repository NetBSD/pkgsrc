# $NetBSD: Makefile,v 1.3 2010/09/10 04:24:49 taca Exp $

DISTNAME=	dbd-odbc-0.2.5
PKGREVISION=	1
CATEGORIES=	databases ruby

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/ruby-dbi/
COMMENT=	ODBC support for Ruby/DBI
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-dbi>=0.4.3:../../databases/ruby-dbi
DEPENDS+=	${RUBY_PKGPREFIX}-odbc>=0.9995:../../databases/ruby-odbc

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

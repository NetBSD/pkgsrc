# $NetBSD: Makefile,v 1.3 2010/09/10 04:29:12 taca Exp $

DISTNAME=	dbd-pg-0.3.9
CATEGORIES=	databases ruby

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/ruby-dbi/
COMMENT=	PostgreSQL support for Ruby/DBI
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-dbi>=0.4.0:../../databases/ruby-dbi
DEPENDS+=	${RUBY_PKGPREFIX}-pg>=0.8.0:../../databases/ruby-pg

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

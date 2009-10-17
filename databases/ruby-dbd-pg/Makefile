# $NetBSD: Makefile,v 1.1.1.1 2009/10/17 12:29:53 taca Exp $

DISTNAME=	dbd-pg-0.3.8
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	databases ruby

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/ruby-dbi/
COMMENT=	PostgreSQL support for Ruby/DBI
LICENSE=	modified-bsd

DEPENDS=	${RUBY_PKGPREFIX}-dbi>=0.4.3:../../databases/ruby-dbi
DEPENDS=	${RUBY_PKGPREFIX}-pg>=0.8.0:../../databases/ruby-pg

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"

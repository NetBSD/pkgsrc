# $NetBSD: Makefile,v 1.1.1.1 2009/10/17 12:28:47 taca Exp $

DISTNAME=	dbd-mysql-0.4.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	databases ruby

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/ruby-dbi/
COMMENT=	MySQL support for Ruby/DBI
LICENSE=	modified-bsd

DEPENDS=	${RUBY_PKGPREFIX}-dbi>=0.4.3:../../databases/ruby-dbi
DEPENDS=	${RUBY_PKGPREFIX}-ruby-mysql>=2.7.6:../../databases/ruby-mysql

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"

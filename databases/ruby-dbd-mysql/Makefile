# $NetBSD: Makefile,v 1.7 2024/02/27 14:38:03 taca Exp $

DISTNAME=	dbd-mysql-0.4.4
PKGREVISION=	2
CATEGORIES=	databases ruby

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	# http://rubyforge.org/projects/ruby-dbi/
COMMENT=	MySQL support for Ruby/DBI
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-dbi>=0.4.3:../../databases/ruby-dbi
DEPENDS+=	${RUBY_PKGPREFIX}-mysql>=2.7.6:../../databases/ruby-mysql

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

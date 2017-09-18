# $NetBSD: Makefile,v 1.6 2017/09/18 02:38:04 taca Exp $

DISTNAME=	dbd-mysql-0.4.4
PKGREVISION=	1
CATEGORIES=	databases ruby

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	# http://rubyforge.org/projects/ruby-dbi/
COMMENT=	MySQL support for Ruby/DBI
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-dbi>=0.4.3:../../databases/ruby-dbi
DEPENDS+=	${RUBY_PKGPREFIX}-mysql28>=2.7.6:../../databases/ruby-mysql28

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

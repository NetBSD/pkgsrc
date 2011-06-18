# $NetBSD: Makefile,v 1.2 2011/06/18 03:29:27 taca Exp $

DISTNAME=	rspec-rails-1.3.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://old.rspec.info/
COMMENT=	Behaviour Driven Development framework for Ruby, core part
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rspec>=1.3.0<2:../../devel/ruby-rspec1
DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.0.0<1.2:../../www/ruby-rack11

RUBY_RAILS=	2

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

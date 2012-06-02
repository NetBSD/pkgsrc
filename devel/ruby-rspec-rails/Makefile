# $NetBSD: Makefile,v 1.6 2012/06/02 00:48:42 taca Exp $

DISTNAME=	rspec-rails-2.10.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://relishapp.com/rspec
COMMENT=	A test-double framework for rspec
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_ACTIONPACK_DEPENDS}
DEPENDS+=	${RUBY_RAILTIES_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-rspec>=2.10.0<2.11:../../devel/ruby-rspec

RUBY_RAILS_SUPPORTED=

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

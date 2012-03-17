# $NetBSD: Makefile,v 1.4 2012/03/17 15:08:56 taca Exp $

DISTNAME=	rspec-rails-2.8.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://relishapp.com/rspec
COMMENT=	A test-double framework for rspec
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_ACTIONPACK_DEPENDS}
DEPENDS+=	${RUBY_RAILTIES_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-rspec>=2.8.0<2.9:../../devel/ruby-rspec

RUBY_RAILS_SUPPORTED=	3 31 # 32

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

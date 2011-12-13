# $NetBSD: Makefile,v 1.2 2011/12/13 15:55:20 taca Exp $

DISTNAME=	rspec-rails-2.6.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://relishapp.com/rspec
COMMENT=	A test-double framework for rspec
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_ACTIONPACK_DEPENDS}
DEPENDS+=	${RUBY_RAILTIES_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-rspec>=2.6.0<2.7:../../devel/ruby-rspec

RUBY_RAILS_SUPPORTED=	3 31

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

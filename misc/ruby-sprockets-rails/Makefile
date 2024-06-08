# $NetBSD: Makefile,v 1.11 2024/06/08 15:52:49 taca Exp $

DISTNAME=	sprockets-rails-3.5.1
CATEGORIES=	misc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rails/sprockets-rails
COMMENT=	Sprockets Rails integration
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sprockets>=3.0.0:../../misc/ruby-sprockets
DEPENDS+=	${RUBY_ACTIONPACK_DEPENDS}
#DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}

RUBY_RAILS_ACCEPTED=		# empty

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

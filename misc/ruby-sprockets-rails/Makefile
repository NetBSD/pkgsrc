# $NetBSD: Makefile,v 1.12 2024/09/18 15:40:07 taca Exp $

DISTNAME=	sprockets-rails-3.5.2
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

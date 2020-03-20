# $NetBSD: Makefile,v 1.5 2020/03/20 15:11:41 taca Exp $

DISTNAME=	sprockets-rails-3.2.1
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rails/sprockets-rails
COMMENT=	Sprockets Rails integration
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sprockets>=3.0.0:../../misc/ruby-sprockets
DEPENDS+=	${RUBY_ACTIONPACK_DEPENDS}
#DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}

RUBY_RAILS_ACCEPTED=		# defined
RUBY_VERSIONS_INCOMPATIBLE=	24

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

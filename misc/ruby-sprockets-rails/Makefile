# $NetBSD: Makefile,v 1.10 2023/09/03 15:42:32 taca Exp $

DISTNAME=	sprockets-rails-3.4.2
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

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

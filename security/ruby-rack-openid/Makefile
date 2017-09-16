# $NetBSD: Makefile,v 1.6 2017/09/16 19:27:07 wiz Exp $

DISTNAME=	rack-openid-1.4.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	ruby security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/grosser/rack-openid
COMMENT=	Provides a more HTTPish API around the ruby-openid library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.1.0:../../www/ruby-rack
DEPENDS+=	${RUBY_PKGPREFIX}-ruby-openid>=2.1.8:../../security/ruby-ruby-openid

USE_LANGUAGES=	# none

RUBY_VERSIONS_ACCEPTED=	22 23 24	# www/ruby-rack

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

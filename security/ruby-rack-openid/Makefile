# $NetBSD: Makefile,v 1.4 2017/06/06 11:12:05 jperkin Exp $

DISTNAME=	rack-openid-1.4.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	ruby security

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/grosser/rack-openid
COMMENT=	Provides a more HTTPish API around the ruby-openid library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.1.0:../../www/ruby-rack
DEPENDS+=	${RUBY_PKGPREFIX}-ruby-openid>=2.1.8:../../security/ruby-ruby-openid

USE_LANGUAGES=	# none

RUBY_VERSIONS_ACCEPTED=	22 23	# www/ruby-rack

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

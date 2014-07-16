# $NetBSD: Makefile,v 1.2 2014/07/16 07:56:28 rodent Exp $

DISTNAME=	shoulda-3.5.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel meta-pkgs ruby

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/thoughtbot/shoulda
COMMENT=	Making tests easy on the fingers and eyes
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-shoulda-context>=1.0.1<2.0:../../devel/ruby-shoulda-context
DEPENDS+=	${RUBY_PKGPREFIX}-shoulda-matchers>=1.4.1<3.0:../../devel/ruby-shoulda-matchers

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.11 2021/08/22 14:49:05 taca Exp $

DISTNAME=	shoulda-4.0.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel meta-pkgs ruby

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/thoughtbot/shoulda
COMMENT=	Making tests easy on the fingers and eyes
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-shoulda-context>=2.0<3:../../devel/ruby-shoulda-context
DEPENDS+=	${RUBY_PKGPREFIX}-shoulda-matchers>=4.0:../../devel/ruby-shoulda-matchers

USE_LANGUAGES=	# none

GEMSPEC_OVERRIDE+=	shoulda-matchers>=4.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.10 2020/06/14 13:32:57 taca Exp $

DISTNAME=	shoulda-4.0.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel meta-pkgs ruby

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/thoughtbot/shoulda
COMMENT=	Making tests easy on the fingers and eyes
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-shoulda-context>=2.0<3:../../devel/ruby-shoulda-context
DEPENDS+=	${RUBY_PKGPREFIX}-shoulda-matchers>=4.0<5:../../devel/ruby-shoulda-matchers

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

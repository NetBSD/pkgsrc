# $NetBSD: Makefile,v 1.4 2014/08/14 02:18:41 rodent Exp $

DISTNAME=	shoulda-matchers-2.6.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel ruby

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://thoughtbot.com/community/
COMMENT=	Making tests easy on the fingers and eyes
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=3.0.0:../../devel/ruby-activesupport32

USE_LANGUAGES=	# none

RUBY_VERSION_SUPPORTED=	200 193 21

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

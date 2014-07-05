# $NetBSD: Makefile,v 1.1 2014/07/05 12:20:51 rodent Exp $

DISTNAME=	shoulda-matchers-2.6.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel ruby

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://thoughtbot.com/community/
COMMENT=	Making tests easy on the fingers and eyes
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=3.0.0:../../devel/ruby-activesupport32

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

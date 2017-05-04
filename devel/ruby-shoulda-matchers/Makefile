# $NetBSD: Makefile,v 1.6 2017/05/04 15:12:34 taca Exp $

DISTNAME=	shoulda-matchers-2.8.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel ruby

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://thoughtbot.com/community/
COMMENT=	Making tests easy on the fingers and eyes
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=3.0.0:${RUBY_RAILS32_ACTIVESUPPORT}

USE_LANGUAGES=	# none
RUBY_RAILS_SUPPORTED=	32

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

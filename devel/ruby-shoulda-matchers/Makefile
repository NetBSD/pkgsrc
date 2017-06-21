# $NetBSD: Makefile,v 1.8 2017/06/21 15:42:11 taca Exp $

DISTNAME=	shoulda-matchers-2.8.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel ruby

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://thoughtbot.com/community/
COMMENT=	Making tests easy on the fingers and eyes
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}

USE_LANGUAGES=	# none
RUBY_RAILS_SUPPORTED=	32

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

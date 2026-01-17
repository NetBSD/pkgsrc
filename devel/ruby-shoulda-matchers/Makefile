# $NetBSD: Makefile,v 1.27 2026/01/17 16:51:18 taca Exp $

DISTNAME=	shoulda-matchers-7.0.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/thoughtbot/shoulda-matchers
COMMENT=	Making tests easy on the fingers and eyes
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}

USE_LANGUAGES=		# none
RUBY_RAILS_ACCEPTED=	71 72 80

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

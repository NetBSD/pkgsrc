# $NetBSD: Makefile,v 1.12 2019/11/03 10:00:25 rillig Exp $

DISTNAME=	shoulda-matchers-3.1.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel ruby

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://thoughtbot.com/community/
COMMENT=	Making tests easy on the fingers and eyes
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}

USE_LANGUAGES=		# none
RUBY_RAILS_ACCEPTED=	42

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

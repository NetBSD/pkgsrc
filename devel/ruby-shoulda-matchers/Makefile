# $NetBSD: Makefile,v 1.10 2018/03/18 14:21:21 taca Exp $

DISTNAME=	shoulda-matchers-2.8.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel ruby

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://thoughtbot.com/community/
COMMENT=	Making tests easy on the fingers and eyes
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}

USE_LANGUAGES=	# none
RUBY_RAILS_ACCEPTED=	32

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

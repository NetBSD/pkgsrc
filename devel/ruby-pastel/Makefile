# $NetBSD: Makefile,v 1.1 2020/01/19 14:37:02 taca Exp $

DISTNAME=	pastel-0.7.3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://piotrmurach.github.io/tty/
COMMENT=	Terminal strings styling with intuitive and clean API
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-equatable>=0.6<1:../../devel/ruby-equatable
DEPENDS+=	${RUBY_PKGPREFIX}-tty-color>=0.5<1:../../devel/ruby-tty-color

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

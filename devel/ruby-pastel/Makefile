# $NetBSD: Makefile,v 1.2 2020/05/25 13:34:53 taca Exp $

DISTNAME=	pastel-0.7.4
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

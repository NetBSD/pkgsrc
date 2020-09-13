# $NetBSD: Makefile,v 1.3 2020/09/13 15:56:58 taca Exp $

DISTNAME=	pastel-0.8.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://piotrmurach.github.io/tty/
COMMENT=	Terminal strings styling with intuitive and clean API
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-tty-color>=0.5<1:../../devel/ruby-tty-color

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

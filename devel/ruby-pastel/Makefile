# $NetBSD: Makefile,v 1.4 2021/01/11 13:22:09 taca Exp $

DISTNAME=	pastel-0.8.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ttytoolkit.org/
COMMENT=	Terminal strings styling with intuitive and clean API
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-tty-color>=0.5<1:../../devel/ruby-tty-color

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

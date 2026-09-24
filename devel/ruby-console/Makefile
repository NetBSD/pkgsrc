# $NetBSD: Makefile,v 1.26 2026/09/24 04:00:55 taca Exp $

DISTNAME=	console-1.38.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/socketry/console
COMMENT=	Beautiful logging for Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-fiber-local>=1.1:../../devel/ruby-fiber-local
DEPENDS+=	${RUBY_PKGPREFIX}-fiber-annotation>=0:../../devel/ruby-fiber-annotation

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

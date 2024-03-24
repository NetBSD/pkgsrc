# $NetBSD: Makefile,v 1.11 2024/03/24 13:41:35 taca Exp $

DISTNAME=	console-1.23.6
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/socketry/console
COMMENT=	Beautiful logging for Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-fiber-local>=0:../../devel/ruby-fiber-local
DEPENDS+=	${RUBY_PKGPREFIX}-fiber-annotation>=0:../../devel/ruby-fiber-annotation

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

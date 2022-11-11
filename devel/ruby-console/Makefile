# $NetBSD: Makefile,v 1.1 2022/11/11 13:29:25 taca Exp $

DISTNAME=	console-1.16.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/socketry/console
COMMENT=	Beautiful logging for Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-fiber-local>=0:../../devel/ruby-fiber-local

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

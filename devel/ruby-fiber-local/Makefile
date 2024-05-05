# $NetBSD: Makefile,v 1.2 2024/05/05 16:20:10 taca Exp $

DISTNAME=	fiber-local-1.1.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/socketry/fiber-local
COMMENT=	Provides a class-level mixin to make fiber local state easy
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${RUBY_PKGPREFIX}-fiber-storage>=0:../../devel/ruby-fiber-storage

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

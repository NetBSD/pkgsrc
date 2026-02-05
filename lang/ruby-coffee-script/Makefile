# $NetBSD: Makefile,v 1.4 2026/02/05 11:06:33 wiz Exp $

DISTNAME=	coffee-script-2.4.1
CATEGORIES=	lang

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rails/ruby-coffee-script
COMMENT=	Ruby CoffeeScript Compiler
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-coffee-script-source>=0:../../lang/ruby-coffee-script-source
DEPENDS+=	${RUBY_PKGPREFIX}-execjs>=0:../../lang/ruby-execjs

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.3 2015/06/07 13:55:41 taca Exp $

DISTNAME=	coffee-script-2.4.1
CATEGORIES=	lang

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/josh/ruby-coffee-script/
COMMENT=	Ruby CoffeeScript Compiler
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-coffee-script-source>=0:../../lang/ruby-coffee-script-source
DEPENDS+=	${RUBY_PKGPREFIX}-execjs>=0:../../lang/ruby-execjs

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

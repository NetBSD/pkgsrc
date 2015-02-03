# $NetBSD: Makefile,v 1.2 2015/02/03 14:36:36 taca Exp $

DISTNAME=	coffee-script-2.3.0
CATEGORIES=	lang

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/josh/ruby-coffee-script/
COMMENT=	Ruby CoffeeScript Compiler
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-coffee-script-source>=0:../../lang/ruby-coffee-script-source
DEPENDS+=	${RUBY_PKGPREFIX}-execjs>=0:../../lang/ruby-execjs

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

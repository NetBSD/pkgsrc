# $NetBSD: Makefile,v 1.8 2011/12/15 15:04:43 taca Exp $

DISTNAME=	RubyInline-3.11.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/^Ruby//:tl}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.zenspider.com/ZSS/Products/RubyInline/
COMMENT=	Embed C/C++ code directly in Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-ZenTest>=4.3<5:../../devel/ZenTest

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

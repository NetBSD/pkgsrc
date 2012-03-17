# $NetBSD: Makefile,v 1.9 2012/03/17 14:38:07 taca Exp $

DISTNAME=	RubyInline-3.11.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/^Ruby//:tl}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.zenspider.com/ZSS/Products/RubyInline/
COMMENT=	Embed C/C++ code directly in Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-ZenTest>=4.3<5:../../devel/ZenTest

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

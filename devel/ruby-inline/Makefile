# $NetBSD: Makefile,v 1.18 2023/02/04 12:21:42 taca Exp $

DISTNAME=	RubyInline-3.13.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/^Ruby//:tl}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.zenspider.com/ZSS/Products/RubyInline/
COMMENT=	Embed C/C++ code directly in Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-ZenTest>=4.3<5:../../devel/ZenTest

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

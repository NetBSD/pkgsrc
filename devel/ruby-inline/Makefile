# $NetBSD: Makefile,v 1.21 2025/03/16 13:57:37 taca Exp $

DISTNAME=	RubyInline-3.14.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/^Ruby//:tl}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.zenspider.com/ZSS/Products/RubyInline/
COMMENT=	Embed C/C++ code directly in Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-ZenTest>=4.3<5:../../devel/ruby-ZenTest

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

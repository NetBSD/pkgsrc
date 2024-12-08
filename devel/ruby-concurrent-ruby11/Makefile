# $NetBSD: Makefile,v 1.3 2024/12/08 16:26:53 taca Exp $

DISTNAME=	concurrent-ruby-1.1.10
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/concurrent-ruby/&11/}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.concurrent-ruby.com/
COMMENT=	Modern concurrency tools for Ruby
LICENSE=	mit

CONFLICTS+=	${RUBY_PKGPREFIX}-concurrent-ruby<1.2

USE_LANGUAGES=	# empty

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

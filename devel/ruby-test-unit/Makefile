# $NetBSD: Makefile,v 1.48 2022/03/27 14:34:35 taca Exp $

DISTNAME=	test-unit-3.5.3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/test-unit/test-unit/
COMMENT=	Improved version of Test::Unit
LICENSE=	ruby-license

USE_LANGUAGES=	# none

# Ruby 3.1.1 contains conflicting the same version
RUBY_VERSIONS_ACCEPTED=	26 27 30

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

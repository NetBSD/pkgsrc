# $NetBSD: Makefile,v 1.52 2023/05/14 13:42:23 taca Exp $

DISTNAME=	test-unit-3.5.8
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/test-unit/test-unit/
COMMENT=	Improved version of Test::Unit
LICENSE=	ruby-license

USE_LANGUAGES=	# none

# Ruby 3.2.0 has the same version as bundled gems.
RUBY_VERSIONS_ACCEPTED=	27 30 31

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

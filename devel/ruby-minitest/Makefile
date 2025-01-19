# $NetBSD: Makefile,v 1.42 2025/01/19 11:07:21 taca Exp $

DISTNAME=	minitest-5.25.4
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/seattlerb/minitest
COMMENT=	Complete suite of testing facilities for Ruby
LICENSE=	mit

USE_LANGUAGES=	# none

# Ruby 3.4.1 has the same version as bundled gem.
RUBY_VERSIONS_ACCEPTED=	31 32 33

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.8 2026/04/08 14:29:33 taca Exp $

DISTNAME=	benchmark-0.5.0
CATEGORIES=	benchmarks

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby/benchmark
COMMENT=	Performance benchmarking library
LICENSE=	2-clause-bsd OR ruby-license

USE_LANGUAGES=	# none

# Ruby 4.0.0 has the same version as bundled gem.
RUBY_VERSIONS_ACCEPTED=	33 34

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

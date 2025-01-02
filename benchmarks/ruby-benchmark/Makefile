# $NetBSD: Makefile,v 1.2 2025/01/02 06:22:29 taca Exp $

DISTNAME=	benchmark-0.4.0
CATEGORIES=	benchmarks

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby/benchmark
COMMENT=	Performance benchmarking library
LICENSE=	2-clause-bsd OR ruby-license

USE_LANGUAGES=	# none

# Ruby 3.4.1 has benchmark 0.4.0 gem.
RUBY_VERSIONS_ACCEPTED=	31 32 33

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

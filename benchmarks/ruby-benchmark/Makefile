# $NetBSD: Makefile,v 1.5 2025/05/27 16:05:33 taca Exp $

DISTNAME=	benchmark-0.4.0
CATEGORIES=	benchmarks

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby/benchmark
COMMENT=	Performance benchmarking library
LICENSE=	2-clause-bsd OR ruby-license

USE_LANGUAGES=	# none

# Ruby 3.4.4 has benchmark 0.4.0 gem.
RUBY_VERSIONS_ACCEPTED=	32 33

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

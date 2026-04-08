# $NetBSD: Makefile,v 1.7 2026/04/08 14:29:34 taca Exp $

DISTNAME=	reline-0.6.3
CATEGORIES=	devel

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://github.com/ruby/reline
COMMENT=	Alternative GNU Readline or Editline implementation by pure Ruby
LICENSE=	2-clause-bsd OR ruby-license

USE_LANGUAGES=	# none

# Ruby 4.0.0 has the same version as bundled gem.
RUBY_VERSIONS_ACCEPTED=	33 34

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

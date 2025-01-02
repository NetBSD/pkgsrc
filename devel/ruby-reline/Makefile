# $NetBSD: Makefile,v 1.3 2025/01/02 05:26:02 taca Exp $

DISTNAME=	reline-0.6.0
CATEGORIES=	devel

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://rubygems.org/gems/reline/
COMMENT=	Alternative GNU Readline or Editline implementation by pure Ruby
LICENSE=	2-clause-bsd OR ruby-license

USE_LANGUAGES=	# none

# Ruby 3.4.1 has reline 0.6.0 gem.
RUBY_VERSIONS_ACCEPTED=	31 32 33

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

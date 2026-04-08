# $NetBSD: Makefile,v 1.11 2026/04/08 14:29:34 taca Exp $

DISTNAME=	securerandom-0.4.1
CATEGORIES=	security

MAINTAINER=	pkgsrc-user@NetBSD.org
HOMEPAGE=	https://github.com/ruby/securerandom
COMMENT=	Interface for secure random number generator
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

# Ruby 3.4.9 and later have securerandom 0.4.1 gem.
RUBY_VERSIONS_ACCEPTED=	33

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

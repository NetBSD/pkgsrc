# $NetBSD: Makefile,v 1.6 2025/04/16 15:23:07 taca Exp $

DISTNAME=	securerandom-0.4.1
CATEGORIES=	security

MAINTAINER=	pkgsrc-user@NetBSD.org
HOMEPAGE=	https://github.com/ruby/securerandom
COMMENT=	Interface for secure random number generator
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

# Ruby 3.4.3 has securerandom 0.4.1 gem.
RUBY_VERSIONS_ACCEPTED=	31 32 33

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

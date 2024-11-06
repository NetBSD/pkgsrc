# $NetBSD: Makefile,v 1.2 2024/11/06 15:32:13 taca Exp $

DISTNAME=	securerandom-0.3.1
CATEGORIES=	security

MAINTAINER=	pkgsrc-user@NetBSD.org
HOMEPAGE=	https://github.com/ruby/securerandom
COMMENT=	Interface for secure random number generator
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

# Ruby 3.3.6 has the same version as default gems.
RUBY_VERSIONS_ACCEPTED=	31 32

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.10 2025/01/19 11:07:21 taca Exp $

DISTNAME=	net-smtp-0.5.0
CATEGORIES=	net mail

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby/net-smtp
COMMENT=	Simple Mail Transfer Protocol client library for Ruby
LICENSE=	2-clause-bsd OR ruby-license

USE_LANGUAGES=	# none

# Ruby 3.4.1 has the same version as bundled gem.
RUBY_VERSIONS_ACCEPTED=	31 32 33

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

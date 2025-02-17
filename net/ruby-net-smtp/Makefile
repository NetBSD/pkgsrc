# $NetBSD: Makefile,v 1.12 2025/02/17 15:23:55 taca Exp $

DISTNAME=	net-smtp-0.5.1
PKGREVISION=	1
CATEGORIES=	net mail

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby/net-smtp
COMMENT=	Simple Mail Transfer Protocol client library for Ruby
LICENSE=	2-clause-bsd OR ruby-license

USE_LANGUAGES=	# none

# Ruby 3.4.2 has the same version as bundled gem.
RUBY_VERSIONS_ACCEPTED=	31 32 33

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

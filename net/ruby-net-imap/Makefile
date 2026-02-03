# $NetBSD: Makefile,v 1.18 2026/02/03 15:32:34 taca Exp $

DISTNAME=	net-imap-0.6.2
CATEGORIES=	net mail

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby/net-imap
COMMENT=	Ruby client api for Internet Message Access Protocol
LICENSE=	2-clause-bsd OR ruby-license

USE_LANGUAGES=	# none

# Ruby 4.0.1 has the same version as bundled gem.
RUBY_VERSIONS_ACCEPTED=	32 33 34

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

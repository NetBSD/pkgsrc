# $NetBSD: Makefile,v 1.14 2025/05/27 16:05:33 taca Exp $

DISTNAME=	net-imap-0.5.8
CATEGORIES=	net mail

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby/net-imap
COMMENT=	Ruby client api for Internet Message Access Protocol
LICENSE=	2-clause-bsd OR ruby-license

USE_LANGUAGES=	# none

# Ruby 3.4.4 has the same version as a bundled gem
RUBY_VERSIONS_ACCEPTED=	32 33

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

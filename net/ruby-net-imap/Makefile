# $NetBSD: Makefile,v 1.4 2023/05/30 15:11:08 taca Exp $

DISTNAME=	net-imap-0.2.3
PKGREVISION=	1
CATEGORIES=	net mail

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby/net-imap
COMMENT=	Ruby client api for Internet Message Access Protocol
LICENSE=	2-clause-bsd OR ruby-license

USE_LANGUAGES=	# none

# This package is mainly for redmine50 on Ruby 3.0.
# (Ruby 3.1 and later have required net-imap gem as standard gem.)
RUBY_VERSIONS_ACCEPTED=	30

.include "../../lang/ruby/rubyversion.mk"

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

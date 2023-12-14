# $NetBSD: Makefile,v 1.8 2023/12/14 15:25:24 taca Exp $

DISTNAME=	net-pop-0.1.2
CATEGORIES=	net mail

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby/net-pop
COMMENT=	Ruby client library for POP3
LICENSE=	2-clause-bsd OR ruby-license

USE_LANGUAGES=	# none

# This package is mainly for redmine51 on Ruby 3.1.
# (Ruby 3.2 and later have required net-imap gem as standard gem.)
RUBY_VERSIONS_ACCEPTED=	31

.include "../../lang/ruby/rubyversion.mk"

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

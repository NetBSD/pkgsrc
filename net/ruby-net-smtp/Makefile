# $NetBSD: Makefile,v 1.6 2023/09/09 14:03:07 taca Exp $

DISTNAME=	net-smtp-0.3.3
CATEGORIES=	net mail

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby/net-smtp
COMMENT=	Simple Mail Transfer Protocol client library for Ruby
LICENSE=	2-clause-bsd OR ruby-license

USE_LANGUAGES=	# none

# This package is mainly for redmine50 on Ruby and 3.0.
# (Ruby 3.1 and later have required net-smtp gem as standard gem.)
RUBY_VERSIONS_ACCEPTED=	30

.include "../../lang/ruby/rubyversion.mk"

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

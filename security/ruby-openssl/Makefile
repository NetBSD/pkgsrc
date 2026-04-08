# $NetBSD: Makefile,v 1.26 2026/04/08 14:29:34 taca Exp $

DISTNAME=	openssl-3.3.2
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby/openssl
COMMENT=	SSL/TLS and general-purpose cryptography for Ruby
LICENSE=	2-clause-bsd OR ruby-license

USE_LANGUAGES=	c

# Ruby 4.0.0 has newer version as default gem.
RUBY_VERSIONS_ACCEPTED=	33 34

.include "../../lang/ruby/gem.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

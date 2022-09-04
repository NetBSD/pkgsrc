# $NetBSD: Makefile,v 1.3 2022/09/04 05:21:52 taca Exp $

DISTNAME=	net-imap-0.2.3
PKGREVISION=	1
CATEGORIES=	net mail

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby/net-imap
COMMENT=	Ruby client api for Internet Message Access Protocol
LICENSE=	2-clause-bsd OR ruby-license

# This package is mainly for redmine50 on Ruby 2.7.

USE_LANGUAGES=	# none

# Ruby 3.1 has the same version in it.
RUBY_VERSIONS_ACCEPTED=	27 30

.include "../../lang/ruby/rubyversion.mk"
.if ${RUBY_VER} == 27
DEPENDS+=	${RUBY_PKGPREFIX}-net-protocol>=0:../../net/ruby-net-protocol
DEPENDS+=	${RUBY_PKGPREFIX}-digest>=0:../../security/ruby-digest
.endif

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

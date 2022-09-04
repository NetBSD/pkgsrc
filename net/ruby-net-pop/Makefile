# $NetBSD: Makefile,v 1.3 2022/09/04 05:22:41 taca Exp $

DISTNAME=	net-pop-0.1.1
PKGREVISION=	1
CATEGORIES=	net mail

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby/net-pop
COMMENT=	Ruby client library for POP3
LICENSE=	2-clause-bsd OR ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-net-protocol>=0:../../net/ruby-net-protocol
DEPENDS+=	${RUBY_PKGPREFIX}-digest>=0:../../security/ruby-digest

# This package is mainly for redmine50 on Ruby 2.7.

USE_LANGUAGES=	# none

# Ruby 3.0 and 3.1 has the same version in it.
RUBY_VERSIONS_ACCEPTED=	27

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

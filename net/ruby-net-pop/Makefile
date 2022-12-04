# $NetBSD: Makefile,v 1.6 2022/12/04 01:35:10 taca Exp $

DISTNAME=	net-pop-0.1.2
CATEGORIES=	net mail

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby/net-pop
COMMENT=	Ruby client library for POP3
LICENSE=	2-clause-bsd OR ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-net-protocol>=0:../../net/ruby-net-protocol
DEPENDS+=	${RUBY_PKGPREFIX}-digest>=0:../../security/ruby-digest

# This package is mainly for redmine50 on Ruby 2.7.

USE_LANGUAGES=	# none

# Ruby 3.1 has the same version of ruby-digest.
RUBY_VERSIONS_ACCEPTED=	27 30

.include "../../lang/ruby/rubyversion.mk"

.if "net-pop-${RUBY_NET_POP_VER}" == ${DISTNAME}
PKG_SKIP_REASON+=	"${DISTNAME} is included in ${RUBY_BASE}"
.endif

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

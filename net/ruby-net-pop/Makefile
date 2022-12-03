# $NetBSD: Makefile,v 1.5 2022/12/03 12:54:23 taca Exp $

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

.include "../../lang/ruby/rubyversion.mk"

.if "net-pop-${RUBY_NET_POP_VER}" == ${DISTNAME}
PKG_SKIP_REASON+=	"${DISTNAME} is included in ${RUBY_BASE}"
.endif

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

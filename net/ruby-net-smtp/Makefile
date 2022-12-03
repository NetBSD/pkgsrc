# $NetBSD: Makefile,v 1.4 2022/12/03 12:56:15 taca Exp $

DISTNAME=	net-smtp-0.3.3
CATEGORIES=	net mail

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby/net-smtp
COMMENT=	Simple Mail Transfer Protocol client library for Ruby
LICENSE=	2-clause-bsd OR ruby-license

# This package is mainly for redmine50 on Ruby 2.7.

USE_LANGUAGES=	# none

.include "../../lang/ruby/rubyversion.mk"

.if "net-smtp-${RUBY_NET_SMTP_VER}" == ${DISTNAME}
PKG_SKIP_REASON+=	"${DISTNAME} is included in ${RUBY_BASE}"
.endif

.if ${RUBY_VER} == 27
DEPENDS+=	${RUBY_PKGPREFIX}-net-protocol>=0:../../net/ruby-net-protocol
DEPENDS+=	${RUBY_PKGPREFIX}-digest>=0:../../security/ruby-digest
.endif

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

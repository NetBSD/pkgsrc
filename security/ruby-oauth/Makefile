# $NetBSD: Makefile,v 1.25 2026/05/31 06:11:11 taca Exp $

DISTNAME=	oauth-1.1.5
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/oauth-xx/oauth-ruby
COMMENT=	OAuth Core Ruby implementation
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-oauth-tty>=1.0.8<2:../../security/ruby-oauth-tty
DEPENDS+=	${RUBY_PKGPREFIX}-snaky_hash>=2.0.4<3:../../security/ruby-snaky_hash
DEPENDS+=	${RUBY_PKGPREFIX}-version_gem>=1.1.3<2:../../devel/ruby-version_gem

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

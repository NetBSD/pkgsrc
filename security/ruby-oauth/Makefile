# $NetBSD: Makefile,v 1.21 2022/09/11 05:47:10 taca Exp $

DISTNAME=	oauth-1.1.0
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/oauth-xx/oauth-ruby
COMMENT=	OAuth Core Ruby implementation
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-oauth-tty>=1.0<2:../../security/ruby-oauth-tty
DEPENDS+=	${RUBY_PKGPREFIX}-snaky_hash>=2.0<3:../../security/ruby-snaky_hash
DEPENDS+=	${RUBY_PKGPREFIX}-version_gem>=1.1<2:../../devel/ruby-version_gem

USE_LANGUAGES=	# none

RUBY_VERSIONS_INCOMPATIBLE=	26

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

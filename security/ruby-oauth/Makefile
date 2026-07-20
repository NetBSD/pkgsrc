# $NetBSD: Makefile,v 1.28 2026/07/20 05:34:04 taca Exp $

DISTNAME=	oauth-1.1.8
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/oauth-xx/oauth-ruby
COMMENT=	OAuth Core Ruby implementation
LICENSE=	mit

#DEPENDS+=	${RUBY_PKGPREFIX}-anonymous_loader>=0.1.3<1:../../devel/ruby-anonymous_loader
#DEPENDS+=	${RUBY_PKGPREFIX}-auth-sanitizer>=0.2.3<1:../../security/ruby-auth-sanitizer
DEPENDS+=	${RUBY_PKGPREFIX}-oauth-tty>=1.0.13<2:../../security/ruby-oauth-tty
DEPENDS+=	${RUBY_PKGPREFIX}-snaky_hash>=2.0.7<3:../../security/ruby-snaky_hash
#DEPENDS+=	${RUBY_PKGPREFIX}-version_gem>=1.1.14<2:../../devel/ruby-version_gem

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

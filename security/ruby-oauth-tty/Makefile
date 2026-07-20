# $NetBSD: Makefile,v 1.7 2026/07/20 05:30:23 taca Exp $

DISTNAME=	oauth-tty-1.0.13
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby-oauth/oauth-tty
COMMENT=	OAuth 1.0 TTY CLI
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-anonymous_loader>=0.1.3<1:../../devel/ruby-anonymous_loader
DEPENDS+=	${RUBY_PKGPREFIX}-auth-sanitizer>=0.2.3<1:../../security/ruby-auth-sanitizer
#DEPENDS+=	${RUBY_PKGPREFIX}-version_gem>=1.1.14<2:../../devel/ruby-version_gem

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

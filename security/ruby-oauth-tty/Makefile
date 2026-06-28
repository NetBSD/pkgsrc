# $NetBSD: Makefile,v 1.6 2026/06/28 15:06:11 taca Exp $

DISTNAME=	oauth-tty-1.0.12
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby-oauth/oauth-tty
COMMENT=	OAuth 1.0 TTY CLI
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-version_gem>=1.1.12<2:../../devel/ruby-version_gem

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

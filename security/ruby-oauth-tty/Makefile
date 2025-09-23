# $NetBSD: Makefile,v 1.4 2025/09/23 03:27:24 taca Exp $

DISTNAME=	oauth-tty-1.0.6
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/oauth-xx/oauth-tty
COMMENT=	OAuth 1.0 TTY CLI
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-version_gem>=1.1.1<2:../../devel/ruby-version_gem

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

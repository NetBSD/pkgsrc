# $NetBSD: Makefile,v 1.2 2022/10/09 08:24:23 taca Exp $

DISTNAME=	oauth-tty-1.0.5
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/oauth-xx/oauth-tty
COMMENT=	OAuth 1.0 TTY CLI
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-version_gem>=1.1.1<2:../../devel/ruby-version_gem

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

RUBY_VERSIONS_INCOMPATIBLE=	26

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

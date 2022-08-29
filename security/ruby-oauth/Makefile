# $NetBSD: Makefile,v 1.20 2022/08/29 14:20:56 wiz Exp $

DISTNAME=	oauth-1.0.0
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/oauth-xx/oauth-ruby
COMMENT=	OAuth Core Ruby implementation
LICENSE=	mit

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

RUBY_VERSIONS_INCOMPATIBLE=	26

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

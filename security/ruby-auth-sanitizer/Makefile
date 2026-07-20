# $NetBSD: Makefile,v 1.1 2026/07/20 05:13:18 taca Exp $

DISTNAME=	auth-sanitizer-0.2.3
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby-oauth/auth-sanitizer
COMMENT=	Configurable KV output redaction
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-version_gem>=1.1.14<2:../../devel/ruby-version_gem

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

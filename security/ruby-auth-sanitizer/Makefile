# $NetBSD: Makefile,v 1.2 2026/11/02 07:10:59 taca Exp $

DISTNAME=	auth-sanitizer-0.2.5
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby-oauth/auth-sanitizer
COMMENT=	Configurable KV output redaction
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-version_gem>=1.1.16<2:../../devel/ruby-version_gem

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.7 2026/07/20 05:25:12 taca Exp $

DISTNAME=	snaky_hash-2.0.7
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/oauth-xx/snaky_hash
COMMENT=	Hashie::Mash joint to make #snakelife better
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-hashie>=0.1.0<6:../../misc/ruby-hashie
DEPENDS+=	${RUBY_PKGPREFIX}-version_gem>=1.1.14<2:../../devel/ruby-version_gem

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.1 2022/09/11 05:35:28 taca Exp $

DISTNAME=	snaky_hash-2.0.0
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/oauth-xx/snaky_hash
COMMENT=	Hashie::Mash joint to make #snakelife better
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-hashie>=0:../../misc/ruby-hashie
DEPENDS+=	${RUBY_PKGPREFIX}-version_gem>=1.1<2:../../devel/ruby-version_gem

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

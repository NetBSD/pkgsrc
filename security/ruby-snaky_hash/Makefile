# $NetBSD: Makefile,v 1.8 2026/11/07 14:50:46 taca Exp $

DISTNAME=	snaky_hash-2.0.9
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby-oauth/snaky_hash
COMMENT=	Hashie::Mash joint to make #snakelife better
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-hashie>=0.1.0<6:../../misc/ruby-hashie
DEPENDS+=	${RUBY_PKGPREFIX}-version_gem>=1.1.16<2:../../devel/ruby-version_gem

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

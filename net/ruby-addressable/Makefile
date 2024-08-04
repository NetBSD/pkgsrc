# $NetBSD: Makefile,v 1.27 2024/08/04 07:19:24 tsutsui Exp $

DISTNAME=	addressable-2.8.7
CATEGORIES=	net

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/sporkmonger/addressable
COMMENT=	Replacement for the URI Implementation of standard librrary
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-public_suffix>=2.0.2<7.0:../../net/ruby-public_suffix

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

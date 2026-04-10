# $NetBSD: Makefile,v 1.30 2026/04/10 13:56:03 tsutsui Exp $

DISTNAME=	addressable-2.9.0
CATEGORIES=	net

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/sporkmonger/addressable
COMMENT=	Replacement for the URI Implementation of standard librrary
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-public_suffix>=2.0.2<8.0:../../net/ruby-public_suffix

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

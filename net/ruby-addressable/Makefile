# $NetBSD: Makefile,v 1.21 2019/10/19 08:16:24 tsutsui Exp $

DISTNAME=	addressable-2.7.0
CATEGORIES=	net

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/sporkmonger/addressable
COMMENT=	Replacement for the URI Implementation of standard librrary
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-public_suffix>=2.0.2:../../net/ruby-public_suffix

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

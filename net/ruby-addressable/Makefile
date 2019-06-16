# $NetBSD: Makefile,v 1.20 2019/06/16 16:01:30 tsutsui Exp $

DISTNAME=	addressable-2.6.0
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sporkmonger/addressable
COMMENT=	Replacement for the URI Implementation of standard librrary
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-public_suffix>=2.0.2:../../net/ruby-public_suffix

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

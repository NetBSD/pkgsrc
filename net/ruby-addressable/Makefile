# $NetBSD: Makefile,v 1.17 2017/01/18 09:03:39 wiz Exp $

DISTNAME=	addressable-2.5.0
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sporkmonger/addressable
COMMENT=	Replacement for the URI Implementation of standard librrary
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-public_suffix>=2.0.2:../../net/ruby-public_suffix

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

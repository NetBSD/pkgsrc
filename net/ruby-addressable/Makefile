# $NetBSD: Makefile,v 1.16 2017/01/09 13:36:12 taca Exp $

DISTNAME=	addressable-2.5.0
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sporkmonger/addressable
COMMENT=	Replacement for the URI Implementation of standard librrary
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-public_suffix>=.2.0.2:../../net/ruby-public_suffix

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

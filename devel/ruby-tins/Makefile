# $NetBSD: Makefile,v 1.43 2026/11/04 15:05:37 taca Exp $

DISTNAME=	tins-1.61.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/flori/tins
COMMENT=	Not good/big enough for a real library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sync>=0:../../devel/ruby-sync
DEPENDS+=	${RUBY_PKGPREFIX}-mize>=0.6<1:../../devel/ruby-mize

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

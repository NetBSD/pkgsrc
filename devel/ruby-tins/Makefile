# $NetBSD: Makefile,v 1.41 2026/09/24 04:14:37 taca Exp $

DISTNAME=	tins-1.57.0
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

# $NetBSD: Makefile,v 1.27 2024/05/05 16:58:16 taca Exp $

DISTNAME=	tins-1.33.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/flori/tins
COMMENT=	Not good/big enough for a real library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sync>=0:../../devel/ruby-sync

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

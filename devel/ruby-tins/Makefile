# $NetBSD: Makefile,v 1.26 2022/11/30 14:23:07 taca Exp $

DISTNAME=	tins-1.32.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/flori/tins
COMMENT=	Not good/big enough for a real library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sync>=0:../../devel/ruby-sync

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

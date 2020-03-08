# $NetBSD: Makefile,v 1.4 2020/03/08 14:51:11 taca Exp $

DISTNAME=	pathutil-0.16.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/envygeeks/pathutil
COMMENT=	Almost like Pathname but just a little less insane
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-forwardable-extended>=2.6<3:../../devel/ruby-forwardable-extended

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

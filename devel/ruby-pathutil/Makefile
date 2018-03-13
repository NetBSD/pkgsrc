# $NetBSD: Makefile,v 1.3 2018/03/13 17:26:39 taca Exp $

DISTNAME=	pathutil-0.16.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/envygeeks/pathutil
COMMENT=	Almost like Pathname but just a little less insane
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-forwardable-extended>=2.6<3:../../devel/ruby-forwardable-extended

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

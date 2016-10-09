# $NetBSD: Makefile,v 1.1 2016/10/09 14:36:51 taca Exp $

DISTNAME=	pathutil-0.14.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/envygeeks/pathutils
COMMENT=	Almost like Pathname but just a little less insane
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-forwardable-extended>=2.6<3:../../devel/ruby-forwardable-extended

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

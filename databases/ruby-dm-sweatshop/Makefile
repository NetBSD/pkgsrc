# $NetBSD: Makefile,v 1.2 2017/07/30 22:32:13 wiz Exp $

DISTNAME=	dm-sweatshop-1.2.0
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/datamapper/dm-sweatshop
COMMENT=	DataMapper plugin for building pseudo random models
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-dm-core>=1.2.0<1.3:../../databases/ruby-dm-core
DEPENDS+=	${RUBY_PKGPREFIX}-randexp>=0.1.5<0.2:../../devel/ruby-randexp
DEPENDS+=	${RUBY_PKGPREFIX}-parsetree>=3.0.7<3.1:../../devel/ruby-parsetree

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

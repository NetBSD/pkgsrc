# $NetBSD: Makefile,v 1.8 2017/07/30 22:32:12 wiz Exp $

DISTNAME=	dm-active_model-1.2.1
PKGREVISION=	3
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/datamapper/dm-active_model
COMMENT=	Plugin to make datamapper active_model compliant
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-dm-core>=1.2.0<1.3:../../databases/ruby-dm-core
DEPENDS+=	${RUBY_ACTIVEMODEL_DEPENDS}

RUBY_RAILS_SUPPORTED=	32

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

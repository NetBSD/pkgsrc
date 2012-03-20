# $NetBSD: Makefile,v 1.2 2012/03/20 10:15:59 taca Exp $

DISTNAME=	dm-active_model-1.2.1
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/datamapper/dm-active_model
COMMENT=	active_model compliance for datamapper
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-dm-core>=1.2.0<1.3:../../databases/ruby-dm-core
DEPENDS+=	${RUBY_ACTIVEMODEL_DEPENDS}

RUBY_RAILS_SUPPORTED=	3

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

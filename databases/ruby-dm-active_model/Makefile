# $NetBSD: Makefile,v 1.3 2012/06/14 15:14:09 taca Exp $

DISTNAME=	dm-active_model-1.2.1
PKGREVISION=	1
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

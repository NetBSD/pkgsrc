# $NetBSD: Makefile,v 1.1.1.1 2011/12/17 17:19:49 taca Exp $

DISTNAME=	dm-do-adapter-1.2.0
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/datamapper/dm-do-adapter
COMMENT=	DataObjects Adapter for DataMapper
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-data_objects>=0.10.6<0.11:../../databases/ruby-data_objects
DEPENDS+=	${RUBY_PKGPREFIX}-dm-core>=1.2.0<1.3:../../databases/ruby-dm-core

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

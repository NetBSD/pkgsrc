# $NetBSD: Makefile,v 1.1.1.1 2010/09/11 23:50:47 taca Exp $

DISTNAME=	dm-constraints-1.0.2
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/datamapper/dm-constraints
COMMENT=	DataMapper plugin constraining relationships
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-dm-core>=1.0.2:../../databases/ruby-dm-core
DEPENDS+=	${RUBY_PKGPREFIX}-dm-migrations>=1.0.2:../../databases/ruby-dm-migrations

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

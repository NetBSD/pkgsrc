# $NetBSD: Makefile,v 1.10 2015/02/17 14:49:10 taca Exp $

DISTNAME=	do_postgres-0.10.15
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dataobjects.info/
COMMENT=	PostgreSQL driver for DataObjects
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-data_objects>=0.10.15<0.11:../../databases/ruby-data_objects

USE_GCC_RUNTIME=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

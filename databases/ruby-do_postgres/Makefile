# $NetBSD: Makefile,v 1.1.1.1 2011/12/17 17:13:07 taca Exp $

DISTNAME=	do_postgres-0.10.7
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dataobjects.info/
COMMENT=	PostgreSQL driver for DataObjects
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-data_objects>=0.10.7<0.11:../../databases/ruby-data_objects

.include "../../lang/ruby/gem.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

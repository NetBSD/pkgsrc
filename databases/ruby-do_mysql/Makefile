# $NetBSD: Makefile,v 1.10 2014/03/13 18:16:36 taca Exp $

DISTNAME=	do_mysql-0.10.14
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dataobjects.info/
COMMENT=	MySQL driver for DataObjects
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-data_objects>=0.10.14<0.11:../../databases/ruby-data_objects

USE_GCC_RUNTIME=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

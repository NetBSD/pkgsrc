# $NetBSD: Makefile,v 1.15 2021/06/23 20:33:09 nia Exp $

DISTNAME=	do_mysql-0.10.17
PKGREVISION=	1
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://dataobjects.info/
COMMENT=	MySQL driver for DataObjects
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-data_objects>=0.10.16<0.11:../../databases/ruby-data_objects

USE_GCC_RUNTIME=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

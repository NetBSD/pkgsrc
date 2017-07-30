# $NetBSD: Makefile,v 1.4 2017/07/30 22:32:13 wiz Exp $

DISTNAME=	dm-mysql-adapter-1.2.0
PKGREVISION=	2
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/datamapper/dm-mysql-adapter
COMMENT=	MySQL Adapter for DataMapper
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-do_mysql>=0.10.6<0.11:../../databases/ruby-do_mysql
DEPENDS+=	${RUBY_PKGPREFIX}-dm-do-adapter>=1.2.0<1.3:../../databases/ruby-dm-do-adapter

.include "../../lang/ruby/gem.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

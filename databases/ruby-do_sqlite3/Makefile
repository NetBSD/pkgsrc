# $NetBSD: Makefile,v 1.20 2015/04/06 08:17:23 adam Exp $

DISTNAME=	do_sqlite3-0.10.15
PKGREVISION=	1
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	#
COMMENT=	Implements the DataObjects API for Sqlite3
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-data_objects>=0.10.15<0.11:../../databases/ruby-data_objects

USE_GCC_RUNTIME=	yes

.include "../../lang/ruby/gem.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

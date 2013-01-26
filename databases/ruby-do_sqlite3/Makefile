# $NetBSD: Makefile,v 1.10 2013/01/26 21:37:16 adam Exp $

DISTNAME=	do_sqlite3-0.10.11
PKGREVISION=	1
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	#
COMMENT=	Implements the DataObjects API for Sqlite3
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-data_objects>=0.10.7<0.11:../../databases/ruby-data_objects

.include "../../lang/ruby/gem.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

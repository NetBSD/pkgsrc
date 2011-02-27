# $NetBSD: Makefile,v 1.1.1.1.4.1 2011/02/27 00:26:12 tron Exp $

DISTNAME=	do_sqlite3-0.10.2
PKGREVISION=	1
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	#
COMMENT=	Implements the DataObjects API for Sqlite3
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-data_objects>=0.10.2:../../databases/ruby-data_objects

.include "../../lang/ruby/gem.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

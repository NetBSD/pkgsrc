# $NetBSD: Makefile,v 1.1.1.1 2011/12/17 17:31:56 taca Exp $

DISTNAME=	dm-sqlite-adapter-1.2.0
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/datamapper/dm-sqlite-adapter
COMMENT=	Sqlite3 Adapter for DataMapper
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-do_sqlite3>=0.10.6<0.11:../../databases/ruby-do_sqlite3
DEPENDS+=	${RUBY_PKGPREFIX}-dm-do-adapter>=1.2.0<1.3:../../databases/ruby-dm-do-adapter

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

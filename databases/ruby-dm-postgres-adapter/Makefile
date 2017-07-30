# $NetBSD: Makefile,v 1.2 2017/07/30 22:32:13 wiz Exp $

DISTNAME=	dm-postgres-adapter-1.2.0
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/datamapper/dm-postgres-adapter
COMMENT=	PostgreSQL Adapter for DataMapper
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-dm-core>=1.2.0<1.3:../../databases/ruby-dm-core
DEPENDS+=	${RUBY_PKGPREFIX}-do_postgres>=0.10.6<0.11:../../databases/ruby-do_postgres
DEPENDS+=	${RUBY_PKGPREFIX}-dm-do-adapter>=1.2.0<1.3:../../databases/ruby-dm-do-adapter

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

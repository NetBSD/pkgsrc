# $NetBSD: Makefile,v 1.3 2011/12/16 14:35:37 taca Exp $

DISTNAME=	dm-migrations-1.2.0
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/datamapper/dm-migrations
COMMENT=	DataMapper plugin for writing and speccing migrations
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-dm-core>=1.2.0<1.3:../../databases/ruby-dm-core

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

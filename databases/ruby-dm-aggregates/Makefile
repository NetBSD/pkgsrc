# $NetBSD: Makefile,v 1.4 2017/07/30 22:32:12 wiz Exp $

DISTNAME=	dm-aggregates-1.2.0
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/datamapper/dm-aggregates
COMMENT=	DataMapper plugin for aggregates on collections
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-dm-core>=1.2.0<1.3:../../databases/ruby-dm-core

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

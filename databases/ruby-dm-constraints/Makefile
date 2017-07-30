# $NetBSD: Makefile,v 1.4 2017/07/30 22:32:12 wiz Exp $

DISTNAME=	dm-constraints-1.2.0
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/datamapper/dm-constraints
COMMENT=	DataMapper plugin constraining relationships
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-dm-core>=1.2.0<1.3:../../databases/ruby-dm-core

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.1.1.1 2011/12/17 17:29:57 taca Exp $

DISTNAME=	dm-observer-1.2.0
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/datamapper/dm-observer
COMMENT=	DataMapper plugin for observing Resources
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-dm-core>=1.2.0<1.3:../../databases/ruby-dm-core

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

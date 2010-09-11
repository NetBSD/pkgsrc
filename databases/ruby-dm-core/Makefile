# $NetBSD: Makefile,v 1.1.1.1 2010/09/11 23:48:54 taca Exp $

DISTNAME=	dm-core-1.0.2
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/datamapper/dm-core
COMMENT=	Object/Relational Mapper for Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-extlib>=0.9.15:../../devel/ruby-extlib
DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=2.2:../../net/ruby-addressable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

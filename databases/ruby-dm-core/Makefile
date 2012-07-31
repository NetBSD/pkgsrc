# $NetBSD: Makefile,v 1.4 2012/07/31 11:45:22 taca Exp $

DISTNAME=	dm-core-1.2.0
PKGREVISION=	1
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/datamapper/dm-core
COMMENT=	Object/Relational Mapper for Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=2.2.4<3:../../net/ruby-addressable

OVERRIDE_GEMSPEC+= addressable~>2.3

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

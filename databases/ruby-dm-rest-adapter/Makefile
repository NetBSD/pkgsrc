# $NetBSD: Makefile,v 1.1.1.1 2011/12/17 17:31:17 taca Exp $

DISTNAME=	dm-rest-adapter-1.2.0
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/datamapper/dm-rest-adapter
COMMENT=	REST Adapter for DataMapper
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-dm-serializer>=1.2.0<1.3:../../databases/ruby-dm-serializer

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.2 2017/07/30 22:32:13 wiz Exp $

DISTNAME=	dm-rest-adapter-1.2.0
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/datamapper/dm-rest-adapter
COMMENT=	REST Adapter for DataMapper
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-dm-serializer>=1.2.0<1.3:../../databases/ruby-dm-serializer

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

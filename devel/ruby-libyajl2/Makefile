# $NetBSD: Makefile,v 1.1 2015/01/19 20:43:37 fhajny Exp $

DISTNAME=	libyajl2-1.2.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/opscode/libyajl2-gem
COMMENT=	Vendored copy of libyajl2
LICENSE=	apache-2.0

MAKE_ENV+=	USE_SYSTEM_LIBYAJL2=yes

.include "../../lang/ruby/gem.mk"
.include "../../devel/yajl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

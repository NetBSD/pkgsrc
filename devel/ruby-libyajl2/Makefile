# $NetBSD: Makefile,v 1.2 2019/02/03 14:42:25 taca Exp $

DISTNAME=	libyajl2-2.0.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/opscode/libyajl2-gem
COMMENT=	Vendored copy of libyajl2
LICENSE=	apache-2.0

MAKE_ENV+=	USE_SYSTEM_LIBYAJL2=yes

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../devel/yajl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

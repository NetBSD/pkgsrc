# $NetBSD: Makefile,v 1.2 2017/07/30 22:32:12 wiz Exp $

DISTNAME=	dm-is-list-1.2.0
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/datamapper/dm-is-list
COMMENT=	DataMapper plugin for creating and organizing lists
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-dm-adjust>=1.2.0<1.3:../../databases/ruby-dm-adjust

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

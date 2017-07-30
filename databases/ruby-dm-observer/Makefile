# $NetBSD: Makefile,v 1.2 2017/07/30 22:32:13 wiz Exp $

DISTNAME=	dm-observer-1.2.0
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/datamapper/dm-observer
COMMENT=	DataMapper plugin for observing Resources
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-dm-core>=1.2.0<1.3:../../databases/ruby-dm-core

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

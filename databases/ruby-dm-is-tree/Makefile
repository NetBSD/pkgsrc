# $NetBSD: Makefile,v 1.2 2017/07/30 22:32:13 wiz Exp $

DISTNAME=	dm-is-tree-1.2.0
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/datamapper/dm-is-tree
COMMENT=	DataMapper plugin allowing the creation of tree structures

DEPENDS+=	${RUBY_PKGPREFIX}-dm-core>=1.2.0<1.3:../../databases/ruby-dm-core

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

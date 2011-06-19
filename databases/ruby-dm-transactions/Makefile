# $NetBSD: Makefile,v 1.2 2011/06/19 08:26:58 taca Exp $

DISTNAME=	dm-transactions-1.1.0
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/datamapper/dm-transactions
COMMENT=	Adds transaction support to datamapper
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-dm-core>=1.1.0<1.2:../../databases/ruby-dm-core

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

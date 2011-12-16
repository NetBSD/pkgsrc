# $NetBSD: Makefile,v 1.3 2011/12/16 14:46:07 taca Exp $

DISTNAME=	dm-transactions-1.2.0
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/datamapper/dm-transactions
COMMENT=	Adds transaction support to datamapper
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-dm-core>=1.2.0<1.3:../../databases/ruby-dm-core

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

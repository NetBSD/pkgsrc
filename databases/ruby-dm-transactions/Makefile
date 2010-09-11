# $NetBSD: Makefile,v 1.1.1.1 2010/09/11 23:53:11 taca Exp $

DISTNAME=	dm-transactions-1.0.2
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/datamapper/dm-transactions
COMMENT=	Adds transaction support to datamapper
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-dm-core>=1.0.2:../../databases/ruby-dm-core

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.1.1.1 2011/12/17 17:24:43 taca Exp $

DISTNAME=	dm-is-nested_set-1.2.0
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/datamapper/dm-is-nested_set
COMMENT=	DataMapper plugin allowing the creation of nested sets from data models
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-dm-adjust>=1.2.0<1.3:../../databases/ruby-dm-adjust

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

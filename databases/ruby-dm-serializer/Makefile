# $NetBSD: Makefile,v 1.2 2011/06/19 08:28:15 taca Exp $

DISTNAME=	dm-serializer-1.1.0
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/datamapper/dm-serializer
COMMENT=	DataMapper plugin for serializing Resources and Collections
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-dm-core>=1.1.0<1.2:../../databases/ruby-dm-core
DEPENDS+=	${RUBY_PKGPREFIX}-fastercsv>=1.5.4<1.6:../../textproc/ruby-fastercsv/

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.1.1.1 2010/09/11 23:53:41 taca Exp $

DISTNAME=	dm-types-1.0.2
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/datamapper/dm-types
COMMENT=	DataMapper plugin providing extra data types
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-dm-core>=1.0.2:../../databases/ruby-dm-core
DEPENDS+=	${RUBY_PKGPREFIX}-json-pure>=1.4.3:../../textproc/ruby-json-pure
DEPENDS+=	${RUBY_PKGPREFIX}-uuidtools>=2.1.1:../../devel/ruby-uuidtools
DEPENDS+=	${RUBY_PKGPREFIX}-stringex>=1.1.0:../../textproc/ruby-stringex

.include "../../lang/ruby/gem.mk"

.if ${RUBY_VER} == "18"
DEPENDS+=	${RUBY_PKGPREFIX}-fastercsv>=1.5.3:../../textproc/ruby-fastercsv
.endif

.include "../../mk/bsd.pkg.mk"

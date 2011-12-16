# $NetBSD: Makefile,v 1.6 2011/12/16 14:47:17 taca Exp $

DISTNAME=	dm-types-1.2.1
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/datamapper/dm-types
COMMENT=	DataMapper plugin providing extra data types
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-bcrypt>=3.0.0<3.1:../../security/ruby-bcrypt
DEPENDS+=	${RUBY_PKGPREFIX}-dm-core>=1.2.0<1.3:../../databases/ruby-dm-core
DEPENDS+=	${RUBY_PKGPREFIX}-fastercsv>=1.5.4<1.6:../../textproc/ruby-fastercsv
DEPENDS+=	${RUBY_PKGPREFIX}-multi_json>=1.0.3<1.1:../../textproc/ruby-multi_json
DEPENDS+=	${RUBY_PKGPREFIX}-stringex>=1.3.0<1.4:../../textproc/ruby-stringex
DEPENDS+=	${RUBY_PKGPREFIX}-uuidtools>=2.1.2<2.2:../../devel/ruby-uuidtools

RUBY_JSON_REQD=		1.5.4

.include "../../lang/ruby/gem.mk"
.include "../../lang/ruby/json.mk"
.include "../../mk/bsd.pkg.mk"

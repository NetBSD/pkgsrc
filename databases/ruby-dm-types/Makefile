# $NetBSD: Makefile,v 1.11 2017/06/01 04:36:56 taca Exp $

DISTNAME=	dm-types-1.2.2
PKGREVISION=	1
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/datamapper/dm-types
COMMENT=	DataMapper plugin providing extra data types
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-bcrypt>=3.0<4:../../security/ruby-bcrypt
DEPENDS+=	${RUBY_PKGPREFIX}-dm-core>=1.2.0<1.3:../../databases/ruby-dm-core
DEPENDS+=	${RUBY_PKGPREFIX}-fastercsv>=1.5<2:../../textproc/ruby-fastercsv
DEPENDS+=	${RUBY_PKGPREFIX}-multi_json>=1.0<2:../../textproc/ruby-multi_json
DEPENDS+=	${RUBY_PKGPREFIX}-stringex>=1.4<2:../../textproc/ruby-stringex
DEPENDS+=	${RUBY_PKGPREFIX}-uuidtools>=2.1<3:../../devel/ruby-uuidtools

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

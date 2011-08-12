# $NetBSD: Makefile,v 1.3 2011/08/12 16:47:08 taca Exp $

DISTNAME=	dm-types-1.1.0
PKGREVISION=	1
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/datamapper/dm-types
COMMENT=	DataMapper plugin providing extra data types
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-bcrypt>=2.1.4<2.2:../../security/ruby-bcrypt
DEPENDS+=	${RUBY_PKGPREFIX}-dm-core>=1.1.0<1.2:../../databases/ruby-dm-core
DEPENDS+=	${RUBY_PKGPREFIX}-json-pure>=1.4.6:../../textproc/ruby-json-pure
DEPENDS+=	${RUBY_PKGPREFIX}-uuidtools>=2.1.2<2.2:../../devel/ruby-uuidtools
DEPENDS+=	${RUBY_PKGPREFIX}-stringex>=1.2.0:../../textproc/ruby-stringex
DEPENDS+=	${RUBY_PKGPREFIX}-fastercsv>=1.5.4<1.6:../../textproc/ruby-fastercsv

OVERRIDE_GEMSPEC+=	json:json_pure>=1.4.6 stringex>=1.2.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

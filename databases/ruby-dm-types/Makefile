# $NetBSD: Makefile,v 1.5 2011/11/23 05:31:53 taca Exp $

DISTNAME=	dm-types-1.1.0
PKGREVISION=	2
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/datamapper/dm-types
COMMENT=	DataMapper plugin providing extra data types
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-bcrypt>=2.1.4:../../security/ruby-bcrypt
DEPENDS+=	${RUBY_PKGPREFIX}-dm-core>=1.1.0<1.2:../../databases/ruby-dm-core
DEPENDS+=	${RUBY_PKGPREFIX}-uuidtools>=2.1.2<2.2:../../devel/ruby-uuidtools
DEPENDS+=	${RUBY_PKGPREFIX}-stringex>=1.2.0:../../textproc/ruby-stringex
DEPENDS+=	${RUBY_PKGPREFIX}-fastercsv>=1.5.4<1.6:../../textproc/ruby-fastercsv

OVERRIDE_GEMSPEC+=	json:json_pure>=1.4.6 stringex>=1.2.0 bcrypt>=2.1.4
RUBY_JSON_REQD=		1.4.6
RUBY_JSON_TYPE=		pure

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

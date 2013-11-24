# $NetBSD: Makefile,v 1.7 2013/11/24 14:07:50 taca Exp $

DISTNAME=	dm-serializer-1.2.2
PKGREVISION=	1
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/datamapper/dm-serializer
COMMENT=	DataMapper plugin for serializing Resources and Collections
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-dm-core>=1.2.0<1.3:../../databases/ruby-dm-core
DEPENDS+=	${RUBY_PKGPREFIX}-fastercsv>=1.5<2:../../textproc/ruby-fastercsv
DEPENDS+=	${RUBY_PKGPREFIX}-multi_json>=1.0<2:../../textproc/ruby-multi_json

OVERRIDE_GEMSPEC+=	json:json_pure>=1.6
RUBY_JSON_REQD=		1.6
RUBY_JSON_TYPE=		pure

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

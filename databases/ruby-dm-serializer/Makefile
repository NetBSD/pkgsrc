# $NetBSD: Makefile,v 1.5 2011/12/16 14:41:27 taca Exp $

DISTNAME=	dm-serializer-1.2.1
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/datamapper/dm-serializer
COMMENT=	DataMapper plugin for serializing Resources and Collections
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-dm-core>=1.2.0<1.3:../../databases/ruby-dm-core
DEPENDS+=	${RUBY_PKGPREFIX}-fastercsv>=1.5.4<1.6:../../textproc/ruby-fastercsv/

OVERRIDE_GEMSPEC+=	json:json_pure>=1.4.6
RUBY_JSON_REQD=		1.4.6
RUBY_JSON_TYPE=		pure

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

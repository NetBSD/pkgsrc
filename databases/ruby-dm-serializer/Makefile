# $NetBSD: Makefile,v 1.4 2011/11/23 05:30:31 taca Exp $

DISTNAME=	dm-serializer-1.1.0
PKGREVISION=	2
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/datamapper/dm-serializer
COMMENT=	DataMapper plugin for serializing Resources and Collections
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-dm-core>=1.1.0<1.2:../../databases/ruby-dm-core
DEPENDS+=	${RUBY_PKGPREFIX}-fastercsv>=1.5.4<1.6:../../textproc/ruby-fastercsv/

OVERRIDE_GEMSPEC+=	json:json_pure>=1.4.6
RUBY_JSON_REQD=		1.4.6
RUBY_JSON_TYPE=		pure

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

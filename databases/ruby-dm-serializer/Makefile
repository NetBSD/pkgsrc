# $NetBSD: Makefile,v 1.1.1.1 2010/09/11 23:52:09 taca Exp $

DISTNAME=	dm-serializer-1.0.2
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/datamapper/dm-serializer
COMMENT=	DataMapper plugin for serializing Resources and Collections
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-dm-core>=1.0.2:../../databases/ruby-dm-core

.include "../../lang/ruby/gem.mk"
.if ${RUBY_VER} == "18"
DEPENDS+=	${RUBY_PKGPREFIX}-fastercsv>=1.5.3:../../textproc/ruby-fastercsv/
.endif

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.1.1.1 2010/09/11 06:53:54 taca Exp $

DISTNAME=	extlib-0.9.15
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/datamapper/extlib
COMMENT=	Support library for DataMapper and Merb
LICENSE=	mit

BUILD_DEPENDS+=	${RUBY_PKGPREFIX}-json-pure>=1.4:../../textproc/ruby-json-pure
BUILD_DEPENDS+=	${RUBY_PKGPREFIX}-rspec>=1.3:../../devel/ruby-rspec

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

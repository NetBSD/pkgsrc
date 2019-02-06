# $NetBSD: Makefile,v 1.33 2019/02/06 15:06:34 taca Exp $

DISTNAME=	bundler-1.17.3
CATEGORIES=	misc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bundler.io/
COMMENT=	Manage your application's dependencies
LICENSE=	mit

#
# Currently, ruby26-base has the same version of bundler.
#
RUBY_VERSIONS_ACCEPTED=	23 24 25

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

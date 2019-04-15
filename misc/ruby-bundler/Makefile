# $NetBSD: Makefile,v 1.34 2019/04/15 06:11:32 wiz Exp $

DISTNAME=	bundler-1.17.3
CATEGORIES=	misc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bundler.io/
COMMENT=	Manage your application's dependencies
LICENSE=	mit

#
# Currently, ruby26-base has the same version of bundler.
#
RUBY_VERSIONS_ACCEPTED=	24 25

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

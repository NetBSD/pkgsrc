# $NetBSD: Makefile,v 1.12 2021/03/09 08:58:23 nia Exp $

DISTNAME=	chef-config-16.10.17
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/chef/chef
COMMENT=	Chef's default configuration and config loading
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-chef-utils>=16.10.17<16.11:../../sysutils/ruby-chef-utils
DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-shellout>=2.0:../../devel/ruby-mixlib-shellout
DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-config>=2.2.12:../../devel/ruby-mixlib-config
DEPENDS+=	${RUBY_PKGPREFIX}-fuzzyurl>=0:../../textproc/ruby-fuzzyurl
DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=0:../../net/ruby-addressable
DEPENDS+=	${RUBY_PKGPREFIX}-tomlrb>=1.2<2:../../devel/ruby-tomlrb

USE_LANGUAGES=	# none

RUBY_VERSIONS_INCOMPATIBLE=	25 # ruby-chef-utils

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

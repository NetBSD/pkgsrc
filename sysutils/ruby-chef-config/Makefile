# $NetBSD: Makefile,v 1.23 2023/04/30 15:29:05 taca Exp $

DISTNAME=	chef-config-18.2.7
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/chef/chef
COMMENT=	Chef's default configuration and config loading
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-chef-utils>=18.2.7<18.3:../../sysutils/ruby-chef-utils
DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-shellout>=2.0<4:../../devel/ruby-mixlib-shellout
DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-config>=2.2.12:../../devel/ruby-mixlib-config
DEPENDS+=	${RUBY_PKGPREFIX}-fuzzyurl>=0:../../textproc/ruby-fuzzyurl
DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=0:../../net/ruby-addressable
DEPENDS+=	${RUBY_PKGPREFIX}-tomlrb>=1.2<2:../../devel/ruby-tomlrb

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

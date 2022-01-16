# $NetBSD: Makefile,v 1.38 2022/01/16 14:29:47 taca Exp $

DISTNAME=	ohai-17.9.0
CATEGORIES=	misc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/opscode/ohai
COMMENT=	Ohai profiles your system and emits JSON
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-chef-config>=14.12:../../sysutils/ruby-chef-config
#DEPENDS+=	${RUBY_PKGPREFIX}-chef-utils>=16.0:../../sysutils/ruby-chef-utils
DEPENDS+=	${RUBY_PKGPREFIX}-ffi>=1.9<2:../../devel/ruby-ffi
DEPENDS+=	${RUBY_PKGPREFIX}-ffi-yajl>=2.2<3:../../devel/ruby-ffi-yajl
DEPENDS+=	${RUBY_PKGPREFIX}-ipaddress>=0.8.0:../../net/ruby-ipaddress
DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-cli>=1.7.0:../../devel/ruby-mixlib-cli
DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-config>=2.0:../../devel/ruby-mixlib-config
DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-log>=2.0.1:../../devel/ruby-mixlib-log
DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-shellout>=3.2<4:../../devel/ruby-mixlib-shellout
DEPENDS+=	${RUBY_PKGPREFIX}-plist>=3.1<4:../../textproc/ruby-plist
DEPENDS+=	${RUBY_PKGPREFIX}-train-core>=0:../../net/ruby-train-core
DEPENDS+=	${RUBY_PKGPREFIX}-wmi-lite>=1.0<2:../../devel/ruby-wmi-lite

USE_LANGUAGES=	# none

RUBY_VERSIONS_ACCEPTED=	27 30 31
RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

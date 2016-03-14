# $NetBSD: Makefile,v 1.3 2016/03/14 00:59:06 tnn Exp $

DISTNAME=	chef-12.0.3
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/opscode/chef
COMMENT=	Configuration management tool for infrastructure automation
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-ffi-yajl>=1.2:../../devel/ruby-ffi-yajl
DEPENDS+=	${RUBY_PKGPREFIX}-highline>=1.6.21<2.0:../../devel/ruby-highline
DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-authentication>=1.3.0<2.0:../../devel/ruby-mixlib-authentication
DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-cli>=1.5.0<2.0:../../devel/ruby-mixlib-cli
DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-config>=2.1.0<3.0:../../devel/ruby-mixlib-config
DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-log>=1.6.0<2.0:../../devel/ruby-mixlib-log
DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-shellout>=2.0<3.0:../../devel/ruby-mixlib-shellout
DEPENDS+=	${RUBY_PKGPREFIX}-ohai>=8.0:../../misc/ruby-ohai
DEPENDS+=	${RUBY_PKGPREFIX}-pry>=0.9.12.6<1.0:../../misc/ruby-pry
DEPENDS+=	${RUBY_PKGPREFIX}-net-ssh>=2.8.0<3.0:../../security/ruby-net-ssh
DEPENDS+=	${RUBY_PKGPREFIX}-net-ssh-gateway>=1.2.0<2.0:../../security/ruby-net-ssh-gateway
DEPENDS+=	${RUBY_PKGPREFIX}-net-ssh-multi>=1.2.0<2.0:../../security/ruby-net-ssh-multi
DEPENDS+=	${RUBY_PKGPREFIX}-chef-zero>=3.2:../../sysutils/ruby-chef-zero
DEPENDS+=	${RUBY_PKGPREFIX}-diff-lcs>=1.2.5<2.0:../../textproc/ruby-diff-lcs
DEPENDS+=	${RUBY_PKGPREFIX}-plist>=3.1.0:../../textproc/ruby-plist
DEPENDS+=	${RUBY_PKGPREFIX}-erubis>=2.7.0<3.0:../../www/ruby-erubis

RUBY_VERSION_SUPPORTED=	21

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

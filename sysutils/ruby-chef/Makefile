# $NetBSD: Makefile,v 1.1 2014/06/03 16:37:21 jperkin Exp $

DISTNAME=	chef-11.12.4
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/opscode/chef
COMMENT=	Configuration management tool for infrastructure automation
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-highline>=1.6.21<2.0:../../devel/ruby-highline
DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-authentication>=1.3.0<2.0:../../devel/ruby-mixlib-authentication
DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-cli>=1.5.0<2.0:../../devel/ruby-mixlib-cli
DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-config>=2.1.0<3.0:../../devel/ruby-mixlib-config
DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-log>=1.6.0<2.0:../../devel/ruby-mixlib-log
DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-shellout>=1.4.0<2.0:../../devel/ruby-mixlib-shellout
DEPENDS+=	${RUBY_PKGPREFIX}-mime-types>=1.25<2.0:../../mail/ruby-mime-types
DEPENDS+=	${RUBY_PKGPREFIX}-ohai>=7.0.4<7.1:../../misc/ruby-ohai
DEPENDS+=	${RUBY_PKGPREFIX}-pry>=0.9.12.6<1.0:../../misc/ruby-pry
DEPENDS+=	${RUBY_PKGPREFIX}-net-ssh>=2.8.0<3.0:../../security/ruby-net-ssh
DEPENDS+=	${RUBY_PKGPREFIX}-net-ssh-gateway>=1.2.0<2.0:../../security/ruby-net-ssh-gateway
DEPENDS+=	${RUBY_PKGPREFIX}-net-ssh-multi>=1.2.0<2.0:../../security/ruby-net-ssh-multi
DEPENDS+=	${RUBY_PKGPREFIX}-chef-zero>=2.0.2<3.0:../../sysutils/ruby-chef-zero
DEPENDS+=	${RUBY_PKGPREFIX}-diff-lcs>=1.2.5<2.0:../../textproc/ruby-diff-lcs
DEPENDS+=	${RUBY_PKGPREFIX}-yajl>=1.1.0<1.2:../../textproc/ruby-yajl
DEPENDS+=	${RUBY_PKGPREFIX}-erubis>=2.7.0<3.0:../../www/ruby-erubis
DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.5.2:../../www/ruby-rack
DEPENDS+=	${RUBY_PKGPREFIX}-rest-client>=1.6.7<1.7:../../www/ruby-rest-client

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

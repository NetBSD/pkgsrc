# $NetBSD: Makefile,v 1.29 2022/01/16 14:29:47 taca Exp $

DISTNAME=	chef-17.8.25
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/opscode/chef
COMMENT=	Configuration management tool for infrastructure automation
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-chef-config>=17.8.25<17.9:../../sysutils/ruby-chef-config
#DEPENDS+=	${RUBY_PKGPREFIX}-chef-utils>=17.8.25<17.9:../../sysutils/ruby-chef-utils
#DEPENDS+=	${RUBY_PKGPREFIX}-train-core>=3.2<4:../../net/ruby-train-core
DEPENDS+=	${RUBY_PKGPREFIX}-train-winrm>=0.2.5:../../net/ruby-train-winrm
#DEPENDS+=	${RUBY_PKGPREFIX}-license-acceptance>=1.0.5:../../misc/ruby-license-acceptance
DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-cli>=2.1.1:../../devel/ruby-mixlib-cli
#DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-log>=2.0.3:../../devel/ruby-mixlib-log
DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-authentication>=2.1:../../devel/ruby-mixlib-authentication
#DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-shellout>=3.1.1:../../devel/ruby-mixlib-shellout
DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-archive>=0.4:../../archivers/ruby-mixlib-archive
DEPENDS+=	${RUBY_PKGPREFIX}-ohai>=17.0<18:../../misc/ruby-ohai
DEPENDS+=	${RUBY_PKGPREFIX}-inspec-core>=4.23<5:../../sysutils/ruby-inspec-core
DEPENDS+=	${RUBY_PKGPREFIX}-ffi>=1.9.25<2:../../devel/ruby-ffi
#DEPENDS+=	${RUBY_PKGPREFIX}-ffi-yajl>=2.2<3:../../devel/ruby-ffi-yajl
DEPENDS+=	${RUBY_PKGPREFIX}-net-sftp>=2.1.2:../../security/ruby-net-sftp
DEPENDS+=	${RUBY_PKGPREFIX}-erubis>=2.7<3:../../www/ruby-erubis
DEPENDS+=	${RUBY_PKGPREFIX}-diff-lcs>=1.2.4:../../textproc/ruby-diff-lcs
DEPENDS+=	${RUBY_PKGPREFIX}-ffi-libarchive>1.0<2:../../archivers/ruby-ffi-libarchive
DEPENDS+=	${RUBY_PKGPREFIX}-chef-zero>=14.0.11:../../sysutils/ruby-chef-zero
DEPENDS+=	${RUBY_PKGPREFIX}-chef-vault>=0:../../security/ruby-chef-vault
DEPENDS+=	${RUBY_PKGPREFIX}-plist>=3.2<4:../../textproc/ruby-plist
DEPENDS+=	${RUBY_PKGPREFIX}-iniparse>=1.4<2:../../devel/ruby-iniparse
#DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=0:../../net/ruby-addressable
DEPENDS+=	${RUBY_PKGPREFIX}-syslog-logger>=1.6<2:../../sysutils/ruby-syslog-logger
DEPENDS+=	${RUBY_PKGPREFIX}-uuidtools>=2.1.5:../../devel/ruby-uuidtools
DEPENDS+=	${RUBY_PKGPREFIX}-proxifier>=1.0<2:../../net/ruby-proxifier
DEPENDS+=	${RUBY_PKGPREFIX}-bundler>=1.10:../../misc/ruby-bundler
DEPENDS+=	${RUBY_PKGPREFIX}-aws-sdk-s3>=1.91<2:../../www/ruby-aws-sdk-s3
DEPENDS+=	${RUBY_PKGPREFIX}-aws-sdk-secretsmanager>=1.46<2:../../www/ruby-aws-sdk-secretsmanager
DEPENDS+=	${RUBY_PKGPREFIX}-vault>=0.16<1:../../security/ruby-vault

USE_LANGUAGES=	# none

RUBY_VERSIONS_ACCEPTED=	27 30 31
RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

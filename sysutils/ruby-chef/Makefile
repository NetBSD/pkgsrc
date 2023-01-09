# $NetBSD: Makefile,v 1.34 2023/01/09 13:03:17 taca Exp $

DISTNAME=	chef-18.1.0
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/opscode/chef
COMMENT=	Configuration management tool for infrastructure automation
LICENSE=	apache-2.0

#DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=0:../../net/ruby-addressable
DEPENDS+=	${RUBY_PKGPREFIX}-aws-sdk-s3>=1.91<2:../../www/ruby-aws-sdk-s3
DEPENDS+=	${RUBY_PKGPREFIX}-aws-sdk-secretsmanager>=1.46<2:../../www/ruby-aws-sdk-secretsmanager
DEPENDS+=	${RUBY_PKGPREFIX}-chef-config>=18.1.0<18.2:../../sysutils/ruby-chef-config
#DEPENDS+=	${RUBY_PKGPREFIX}-chef-utils>=18.1.0<18.2:../../sysutils/ruby-chef-utils
DEPENDS+=	${RUBY_PKGPREFIX}-chef-vault>=0:../../security/ruby-chef-vault
DEPENDS+=	${RUBY_PKGPREFIX}-chef-zero>=14.0.11:../../sysutils/ruby-chef-zero
DEPENDS+=	${RUBY_PKGPREFIX}-corefoundation>=0.3.4<0.4:../../devel/ruby-corefoundation
DEPENDS+=	${RUBY_PKGPREFIX}-diff-lcs>=1.2.4:../../textproc/ruby-diff-lcs
DEPENDS+=	${RUBY_PKGPREFIX}-erubis>=2.7<3:../../www/ruby-erubis
DEPENDS+=	${RUBY_PKGPREFIX}-ffi>=1.15.5:../../devel/ruby-ffi
DEPENDS+=	${RUBY_PKGPREFIX}-ffi-libarchive>1.0.3<2:../../archivers/ruby-ffi-libarchive
#DEPENDS+=	${RUBY_PKGPREFIX}-ffi-yajl>=2.2<3:../../devel/ruby-ffi-yajl
DEPENDS+=	${RUBY_PKGPREFIX}-iniparse>=1.4<2:../../devel/ruby-iniparse
DEPENDS+=	${RUBY_PKGPREFIX}-inspec-core>=5:../../sysutils/ruby-inspec-core
#DEPENDS+=	${RUBY_PKGPREFIX}-license-acceptance>=1.0.5<3:../../misc/ruby-license-acceptance
DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-archive>=0.4<2:../../archivers/ruby-mixlib-archive
DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-authentication>=2.1<4:../../devel/ruby-mixlib-authentication
DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-cli>=2.1.1<3:../../devel/ruby-mixlib-cli
#DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-log>=2.0.3<4:../../devel/ruby-mixlib-log
#DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-shellout>=3.1.1<4:../../devel/ruby-mixlib-shellout
# ruby-net-ftp
DEPENDS+=	${RUBY_PKGPREFIX}-net-sftp>=2.1.2<4:../../security/ruby-net-sftp
DEPENDS+=	${RUBY_PKGPREFIX}-ohai>=18.0<19:../../misc/ruby-ohai
DEPENDS+=	${RUBY_PKGPREFIX}-plist>=3.2<4:../../textproc/ruby-plist
DEPENDS+=	${RUBY_PKGPREFIX}-proxifier>=1.0<2:../../net/ruby-proxifier
DEPENDS+=	${RUBY_PKGPREFIX}-syslog-logger>=1.6<2:../../sysutils/ruby-syslog-logger
#DEPENDS+=	${RUBY_PKGPREFIX}-train-core>=3.10<4:../../net/ruby-train-core
DEPENDS+=	${RUBY_PKGPREFIX}-train-rest>=0.4.1:../../net/ruby-train-rest
DEPENDS+=	${RUBY_PKGPREFIX}-train-winrm>=0.2.5:../../net/ruby-train-winrm
DEPENDS+=	${RUBY_PKGPREFIX}-unf_ext>=0.0.8.2:../../converters/ruby-unf_ext
DEPENDS+=	${RUBY_PKGPREFIX}-uuidtools>=2.1.5<3:../../devel/ruby-uuidtools
DEPENDS+=	${RUBY_PKGPREFIX}-vault>=0.16<1:../../security/ruby-vault

USE_LANGUAGES=	# none

RUBY_VERSIONS_ACCEPTED=	30 31

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

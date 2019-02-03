# $NetBSD: Makefile,v 1.12 2019/02/03 16:10:44 taca Exp $

DISTNAME=	chef-14.10.9
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/opscode/chef
COMMENT=	Configuration management tool for infrastructure automation
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-chef-config>=14.10.9<14.11:../../sysutils/ruby-chef-config
DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-archive>=0.4<2:../../archivers/ruby-mixlib-archive
DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-cli>=1.7<2:../../devel/ruby-mixlib-cli
DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-log>=2.0.3:../../devel/ruby-mixlib-log
DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-authentication>=2.1<3:../../devel/ruby-mixlib-authentication
#DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-shellout>=2.4<3.0:../../devel/ruby-mixlib-shellout
DEPENDS+=	${RUBY_PKGPREFIX}-ohai>=14.0<15:../../misc/ruby-ohai
DEPENDS+=	${RUBY_PKGPREFIX}-ffi>=1.9.25:../../devel/ruby-ffi
#DEPENDS+=	${RUBY_PKGPREFIX}-ffi-yajl>=2.2<3:../../devel/ruby-ffi-yajl
#DEPENDS+=	${RUBY_PKGPREFIX}-net-ssh>=4.2<5:../../security/ruby-net-ssh
DEPENDS+=	${RUBY_PKGPREFIX}-net-ssh-multi>=1.2.1:../../security/ruby-net-ssh-multi
DEPENDS+=	${RUBY_PKGPREFIX}-net-sftp>=2.1.2:../../security/ruby-net-sftp
DEPENDS+=	${RUBY_PKGPREFIX}-highline>=1.6.21:../../devel/ruby-highline
DEPENDS+=	${RUBY_PKGPREFIX}-erubis>=2.7<3:../../www/ruby-erubis
DEPENDS+=	${RUBY_PKGPREFIX}-diff-lcs>=1.2.4:../../textproc/ruby-diff-lcs
DEPENDS+=	${RUBY_PKGPREFIX}-chef-zero>=13.0:../../sysutils/ruby-chef-zero
DEPENDS+=	${RUBY_PKGPREFIX}-plist>=3.2<4:../../textproc/ruby-plist
DEPENDS+=	${RUBY_PKGPREFIX}-iniparse>=1.4<2:../../devel/ruby-iniparse
#DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=0:../../net/ruby-addressable
DEPENDS+=	${RUBY_PKGPREFIX}-rspec-core>=3.5<4:../../devel/ruby-rspec-core
DEPENDS+=	${RUBY_PKGPREFIX}-rspec-expectations>=3.5<4:../../devel/ruby-rspec-expectations
DEPENDS+=	${RUBY_PKGPREFIX}-rspec-mocks>=3.5<4:../../devel/ruby-rspec-mocks
DEPENDS+=	${RUBY_PKGPREFIX}-rspec_junit_formatter>=0.2.0<0.3:../../devel/ruby-rspec_junit_formatter
DEPENDS+=	${RUBY_PKGPREFIX}-serverspec>=2.7<3:../../sysutils/ruby-serverspec
#DEPENDS+=	${RUBY_PKGPREFIX}-specinfra>=2.10<3:../../sysutils/ruby-specinfra
DEPENDS+=	${RUBY_PKGPREFIX}-syslog-logger>=1.6<2:../../sysutils/ruby-syslog-logger
DEPENDS+=	${RUBY_PKGPREFIX}-uuidtools>=2.1.5<2.2:../../devel/ruby-uuidtools
DEPENDS+=	${RUBY_PKGPREFIX}-proxifier>=1.0<2:../../net/ruby-proxifier

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable
RUBY_VERSIONS_ACCEPTED=	24 25 26	# misc/ruby-ohai

pre-configure:
	cd ${WRKSRC}/bin && ${FIND} . -type f -exec ${CHMOD} ${BINMODE} {} \;

.include "../../lang/ruby/gem.mk"
.if ${RUBY_VER} != 26
DEPENDS+=	${RUBY_PKGPREFIX}-bundler>=1.10:../../misc/ruby-bundler
.endif
.include "../../mk/bsd.pkg.mk"

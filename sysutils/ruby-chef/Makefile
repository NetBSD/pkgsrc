# $NetBSD: Makefile,v 1.14 2020/03/26 12:14:01 jperkin Exp $

DISTNAME=	chef-15.8.23
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/opscode/chef
COMMENT=	Configuration management tool for infrastructure automation
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-chef-config>=15.8.23<15.9:../../sysutils/ruby-chef-config
#DEPENDS+=	${RUBY_PKGPREFIX}-chef-utils>=15.8.23<15.9:../../sysutils/ruby-chef-utils
DEPENDS+=	${RUBY_PKGPREFIX}-train-core>=3.1<4:../../net/ruby-train-core
DEPENDS+=	${RUBY_PKGPREFIX}-train-winrm>=0.2.5:../../net/ruby-train-winrm
DEPENDS+=	${RUBY_PKGPREFIX}-license-acceptance>=1.0.5:../../misc/ruby-license-acceptance
DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-cli>=2.1.1:../../devel/ruby-mixlib-cli
DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-log>=2.0.3:../../devel/ruby-mixlib-log
DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-authentication>=2.1:../../devel/ruby-mixlib-authentication
#DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-shellout>=3.0.3:../../devel/ruby-mixlib-shellout
DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-archive>=0.4:../../archivers/ruby-mixlib-archive
DEPENDS+=	${RUBY_PKGPREFIX}-ohai>=15.0<16:../../misc/ruby-ohai
DEPENDS+=	${RUBY_PKGPREFIX}-ffi>=1.9.25<2:../../devel/ruby-ffi
#DEPENDS+=	${RUBY_PKGPREFIX}-ffi-yajl>=2.2<3:../../devel/ruby-ffi-yajl
#DEPENDS+=	${RUBY_PKGPREFIX}-net-ssh>=4.2:../../security/ruby-net-ssh
DEPENDS+=	${RUBY_PKGPREFIX}-net-ssh-multi>=1.2.1:../../security/ruby-net-ssh-multi
DEPENDS+=	${RUBY_PKGPREFIX}-net-sftp>=2.1.2<3:../../security/ruby-net-sftp
DEPENDS+=	${RUBY_PKGPREFIX}-ed25519>=1.2<2:../../security/ruby-ed25519
DEPENDS+=	${RUBY_PKGPREFIX}-bcrypt_pbkdf>=1.0<2:../../security/ruby-bcrypt_pbkdf
DEPENDS+=	${RUBY_PKGPREFIX}-highline>=1.6.21:../../devel/ruby-highline
DEPENDS+=	${RUBY_PKGPREFIX}-tty-screen>=0.6<1:../../devel/ruby-tty-screen
DEPENDS+=	${RUBY_PKGPREFIX}-erubis>=2.7<3:../../www/ruby-erubis
DEPENDS+=	${RUBY_PKGPREFIX}-diff-lcs>=1.2.4:../../textproc/ruby-diff-lcs
DEPENDS+=	${RUBY_PKGPREFIX}-ffi-libarchive>0:../../archivers/ruby-ffi-libarchive
DEPENDS+=	${RUBY_PKGPREFIX}-chef-zero>=14.0.11:../../sysutils/ruby-chef-zero
DEPENDS+=	${RUBY_PKGPREFIX}-plist>=3.2<4:../../textproc/ruby-plist
DEPENDS+=	${RUBY_PKGPREFIX}-iniparse>=1.4<2:../../devel/ruby-iniparse
#DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=0:../../net/ruby-addressable
DEPENDS+=	${RUBY_PKGPREFIX}-syslog-logger>=1.6<2:../../sysutils/ruby-syslog-logger
DEPENDS+=	${RUBY_PKGPREFIX}-uuidtools>=2.1.5<2.2:../../devel/ruby-uuidtools
DEPENDS+=	${RUBY_PKGPREFIX}-proxifier>=1.0<2:../../net/ruby-proxifier

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

pre-configure:
	cd ${WRKSRC}/bin && ${FIND} . -type f -exec ${CHMOD} ${BINMODE} {} \;

.include "../../lang/ruby/gem.mk"
.if ${RUBY_VER} != 26
DEPENDS+=	${RUBY_PKGPREFIX}-bundler>=1.10:../../misc/ruby-bundler
.endif
.include "../../mk/bsd.pkg.mk"

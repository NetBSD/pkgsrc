# $NetBSD: Makefile,v 1.7 2022/01/18 13:35:42 taca Exp $

DISTNAME=	redmine-${RM_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/redmine/redmine${RM_VER}/}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	https://www.redmine.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.redmine.org/
COMMENT=	Flexible project management web application
LICENSE=	gnu-gpl-v2 # and so on.

RM_VERSION=	4.2.3

NO_BUILD=	yes

RUBY_VERSIONS_ACCEPTED=	26 27

RUBY_RAILS_ACCEPTED=	52

OVERRIDE_GEMSPEC+=	nokogiri>=1.11.0 mini_mime>=1.0.1 csv>=3.1.1

.include "../../lang/ruby/modules.mk"

DEPENDS+=	${RUBY_PKGPREFIX}-bundler>=1.5.0:../../misc/ruby-bundler
DEPENDS+=	${RUBY_RAILS_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-rouge>=3.26:../../www/ruby-rouge
DEPENDS+=	${RUBY_PKGPREFIX}-request_store>=1.5.0<1.6:../../www/ruby-request_store
# ruby-mail depends it.
#DEPENDS+=	${RUBY_PKGPREFIX}-mini_mime>=1.0.1<1.1:../../mail/ruby-mini_mime
DEPENDS+=	${RUBY_PKGPREFIX}-actionpack${RUBY_RAILS}-xml_parser>=2.0:../../textproc/ruby-actionpack-xml_parser
DEPENDS+=	${RUBY_PKGPREFIX}-roadie-rails${RUBY_RAILS}>=2.2.0<2.3:../../mail/ruby-roadie-rails
DEPENDS+=	${RUBY_PKGPREFIX}-marcel>=1.0.0:../../devel/ruby-marcel
DEPENDS+=	${RUBY_PKGPREFIX}-mail>=2.7.1<2.8:../../mail/ruby-mail
DEPENDS+=	${RUBY_PKGPREFIX}-csv>=3.1.1:../../textproc/ruby-csv
DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.11.1:../../textproc/ruby-nokogiri
DEPENDS+=	${RUBY_PKGPREFIX}-i18n>=1.8.2<1.9:../../devel/ruby-i18n
DEPENDS+=	${RUBY_PKGPREFIX}-rbpdf>=1.20.0<1.21:../../print/ruby-rbpdf
DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=0:../../net/ruby-addressable
DEPENDS+=	${RUBY_PKGPREFIX}-zip>=2.3.0<2.4:../../archivers/ruby-zip
#DEPENDS+=	${RUBY_PKGPREFIX}-tzinfo-data>=1:../../time/ruby-tzinfo-data
DEPENDS+=	${RUBY_PKGPREFIX}-rotp>=6.2.0:../../security/ruby-rotp
DEPENDS+=	${RUBY_PKGPREFIX}-rqrcode>=1.2.0:../../textproc/ruby-rqrcode
DEPENDS+=	${RUBY_PKGPREFIX}-net-ldap>=0.17.0<0.18:../../net/ruby-net-ldap
DEPENDS+=	${RUBY_PKGPREFIX}-ruby-openid>=2.9.2<2.10:../../security/ruby-ruby-openid
DEPENDS+=	${RUBY_PKGPREFIX}-rack-openid>=1.4.2:../../security/ruby-rack-openid
DEPENDS+=	${RUBY_PKGPREFIX}-mini-magick>=4.11.0<4.12:../../graphics/ruby-mini-magick
DEPENDS+=	${RUBY_PKGPREFIX}-redcarpet>=3.5.1<3.6:../../textproc/ruby-redcarpet

.include "options.mk"

REPLACE_RUBY+=	${DISTNAME}/bin/*
REPLACE_RUBY+=	${DISTNAME}/extra/mail_handler/rdm-mailhandler.rb
REPLACE_RUBY+=	${DISTNAME}/extra/svn/reposman.rb
REPLACE_RUBY+=	${DISTNAME}/public/dispatch.fcgi.example

SUBST_CLASSES+=		shell
SUBST_FILES.shell=	${DESTDIR}${PREFIX}/bin/redmine42_*${RUBY_SUFFIX}.sh
SUBST_MESSAGE.shell=	Fixing paths in helper shell scripts.
SUBST_VARS.shell=	PREFIX RUBY RM_DIR
SUBST_STAGE.shell=	post-install

MESSAGE_SUBST+=	RM_DIR=${RM_DIR}

USE_LANGUAGES=	# none

EGDIR=		${PREFIX}/share/examples/${RUBY_PKGPREFIX}-redmine42
INSTALLATION_DIRS=	bin ${EGDIR} ${RM_DIR} ${RM_DIR}/config

CONF_FILES+=	${EGDIR}/configuration.yml.example \
			${RM_DIR}/config/configuration.yml
CONF_FILES+=	${EGDIR}/database.yml.example \
			${RM_DIR}/config/database.yml
CONF_FILES+=	${EGDIR}/additional_environment.rb.example \
			${RM_DIR}/config/additional_environment.rb
REQD_FILES+=	/dev/null ${RM_DIR}/Gemfile.lock

.include "../../mk/bsd.prefs.mk"

PKG_GROUPS=	${APACHE_GROUP}
PKG_USERS=	${APACHE_USER}:${APACHE_GROUP}
BUILD_DEFS+=	APACHE_GROUP APACHE_USER
FILES_SUBST+=	WWWGRP=${APACHE_GROUP} WWWOWN=${APACHE_USER} \
		RM_DIR=${RM_DIR}

do-install:
	cd ${WRKSRC} && ${FIND} . -type d -exec ${INSTALL_DATA_DIR} \
		${DESTDIR}${PREFIX}/${RM_DIR}/{} \;
	cd ${WRKSRC} && ${FIND} . -type f ! -name "*.orig" -exec \
		${INSTALL_DATA} {} ${DESTDIR}${PREFIX}/${RM_DIR}/{} \;
	${INSTALL_SCRIPT} ${FILESDIR}/redmine42_migrate_plugins.sh \
		${DESTDIR}${PREFIX}/bin/redmine42_migrate_plugins${RUBY_SUFFIX}.sh
	${INSTALL_SCRIPT} ${FILESDIR}/redmine42_generate_secret_token.sh \
		${DESTDIR}${PREFIX}/bin/redmine42_generate_secret_token${RUBY_SUFFIX}.sh
	${INSTALL_SCRIPT} ${FILESDIR}/redmine42_migrate_db.sh \
		${DESTDIR}${PREFIX}/bin/redmine42_migrate_db${RUBY_SUFFIX}.sh
	${INSTALL_SCRIPT} ${FILESDIR}/redmine42_load_default_data.sh \
		${DESTDIR}${PREFIX}/bin/redmine42_load_default_data${RUBY_SUFFIX}.sh

post-install: unicorn-post-install
	${FIND} ${DESTDIR}/ -name ".*" \( -type f -or -type d \) | xargs rm -rf
	${MV} ${DESTDIR}${PREFIX}/${RM_DIR}/config/configuration.yml.example \
		${DESTDIR}/${EGDIR}
	${MV} ${DESTDIR}${PREFIX}/${RM_DIR}/config/database.yml.example \
		${DESTDIR}/${EGDIR}
	${MV} ${DESTDIR}${PREFIX}/${RM_DIR}/config/additional_environment.rb.example \
		${DESTDIR}/${EGDIR}

.include "../../devel/ruby-redmine/redmine.mk"
.include "../../mk/bsd.pkg.mk"

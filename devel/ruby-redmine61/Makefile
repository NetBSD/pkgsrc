# $NetBSD: Makefile,v 1.1.2.1 2026/03/31 13:02:19 maya Exp $

DISTNAME=	redmine-${RM_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/redmine/redmine${RM_VER}/}
CATEGORIES=	devel
MASTER_SITES=	https://www.redmine.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.redmine.org/
COMMENT=	Flexible project management web application
LICENSE=	gnu-gpl-v2 # and so on.

RM_VERSION=	6.1.2

NO_BUILD=	yes

USE_LANGUAGES=	# none

RUBY_VERSIONS_ACCEPTED=	32 33 34
RUBY_RAILS_ACCEPTED=	72

PYTHON_VERSIONS_INCOMPATIBLE=	27

OVERRIDE_GEMSPEC+=	mini-magick>=4.11.0 nokogiri>=1.18.3<1.20

#DEPENDS+=	${RUBY_PKGPREFIX}-bundler>=1.12.0:../../misc/ruby-bundler
DEPENDS+=	${RUBY_RAILS_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-rouge>=4.5.0<5:../../www/ruby-rouge

# ruby-mail depends it.
#DEPENDS+=	${RUBY_PKGPREFIX}-mini_mime>=1.1.0<1.2:../../mail/ruby-mini_mime
DEPENDS+=	${RUBY_PKGPREFIX}-actionpack-xml_parser>=2.0:../../textproc/ruby-actionpack-xml_parser
DEPENDS+=	${RUBY_PKGPREFIX}-roadie-rails33_${RUBY_RAILS}>=3.3.0<3.4:../../mail/ruby-roadie-rails33
DEPENDS+=	${RUBY_PKGPREFIX}-marcel>=1.0.0:../../devel/ruby-marcel
DEPENDS+=	${RUBY_PKGPREFIX}-mail>=2.8.1<2.9:../../mail/ruby-mail
DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.18.3<1.20:../../textproc/ruby-nokogiri
#DEPENDS+=	${RUBY_PKGPREFIX}-i18n>=1.14.1:../../devel/ruby-i18n
DEPENDS+=	${RUBY_PKGPREFIX}-rbpdf>=1.21.4<1.22:../../print/ruby-rbpdf
DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=0:../../net/ruby-addressable
DEPENDS+=	${RUBY_PKGPREFIX}-zip24>=2.4.0<3:../../archivers/ruby-zip24
DEPENDS+=	${RUBY_PKGPREFIX}-propshaft11>=1.1.0<1.2:../../www/ruby-propshaft11
DEPENDS+=	${RUBY_PKGPREFIX}-rack>=3.1.3:../../www/ruby-rack
DEPENDS+=	${RUBY_PKGPREFIX}-stimulus-rails>=1.3<2:../../www/ruby-stimulus-rails
DEPENDS+=	${RUBY_PKGPREFIX}-importmap-rails>=2.0<3:../../www/ruby-importmap-rails
DEPENDS+=	${RUBY_PKGPREFIX}-commonmarker23>=2.3.0<2.4:../../textproc/ruby-commonmarker23
DEPENDS+=	${RUBY_PKGPREFIX}-doorkeeper>=5.8.2<5.9:../../www/ruby-doorkeeper
DEPENDS+=	${RUBY_PKGPREFIX}-bcrypt>=3.0:../../security/ruby-bcrypt
DEPENDS+=	${RUBY_PKGPREFIX}-doorkeeper-i18n>=5.2<6:../../www/ruby-doorkeeper-i18n
DEPENDS+=	${RUBY_PKGPREFIX}-requestjs-rails>=0.0.13<0.1:../../www/ruby-requestjs-rails
#
DEPENDS+=	${RUBY_PKGPREFIX}-rotp>=6.2.0:../../security/ruby-rotp
DEPENDS+=	${RUBY_PKGPREFIX}-rqrcode>=1.2.0:../../textproc/ruby-rqrcode
DEPENDS+=	${RUBY_PKGPREFIX}-html-pipeline>=2.13.2<3:../../textproc/ruby-html-pipeline
DEPENDS+=	${RUBY_PKGPREFIX}-sanitize>=6.0<7:../../textproc/ruby-sanitize
DEPENDS+=	${RUBY_PKGPREFIX}-net-ldap>=0.17.0:../../net/ruby-net-ldap
DEPENDS+=	${RUBY_PKGPREFIX}-mini-magick>=5.2.0:../../graphics/ruby-mini-magick

REPLACE_RUBY+=	bin/*
REPLACE_RUBY+=	extra/mail_handler/rdm-mailhandler.rb
REPLACE_RUBY+=	extra/svn/reposman.rb

SUBST_CLASSES+=		path
SUBST_FILES.path+=	${DESTDIR}${PREFIX}/bin/redmine61_*${RUBY_SUFFIX}.sh
SUBST_FILES.path+=	${DESTDIR}${PREFIX}/${RM_DIR}/README-pkgsrc
SUBST_MESSAGE.path=	Fixing paths in helper shell scripts and documents.
SUBST_VARS.path=	PREFIX RM_DIR RM_VER RUBY RUBY_SUFFIX RCD_SCRIPTS_DIR
SUBST_STAGE.path=	post-install

EGDIR=		${PREFIX}/share/examples/${RUBY_PKGPREFIX}-redmine61
INSTALLATION_DIRS=	bin ${EGDIR} ${RM_DIR} ${RM_DIR}/config

CONF_FILES+=	${EGDIR}/configuration.yml.example \
			${RM_DIR}/config/configuration.yml
CONF_FILES+=	${EGDIR}/database.yml.example \
			${RM_DIR}/config/database.yml
CONF_FILES+=	${EGDIR}/additional_environment.rb.example \
			${RM_DIR}/config/additional_environment.rb
REQD_FILES+=	/dev/null ${RM_DIR}/Gemfile.lock
OWN_DIRS+=	${RM_DIR}/.bundle

PKG_GROUPS=	${APACHE_GROUP}
PKG_USERS=	${APACHE_USER}:${APACHE_GROUP}
BUILD_DEFS+=	APACHE_GROUP APACHE_USER
FILES_SUBST+=	WWWGRP=${APACHE_GROUP} WWWOWN=${APACHE_USER} \
		RM_DIR=${RM_DIR}

do-install:
	cd ${WRKSRC} && ${FIND} . -type d | ${XARGS} -I {} ${INSTALL_DATA_DIR} \
		${DESTDIR}${PREFIX}/${RM_DIR}/{}
	cd ${WRKSRC} && ${FIND} . -type f ! -name "*.orig" | ${XARGS} -I {} \
		${INSTALL_DATA} {} ${DESTDIR}${PREFIX}/${RM_DIR}/{}
	${INSTALL_SCRIPT} ${FILESDIR}/redmine_migrate_plugins.sh \
		${DESTDIR}${PREFIX}/bin/redmine61_migrate_plugins${RUBY_SUFFIX}.sh
	${INSTALL_SCRIPT} ${FILESDIR}/redmine_generate_secret_token.sh \
		${DESTDIR}${PREFIX}/bin/redmine61_generate_secret_token${RUBY_SUFFIX}.sh
	${INSTALL_SCRIPT} ${FILESDIR}/redmine_migrate_db.sh \
		${DESTDIR}${PREFIX}/bin/redmine61_migrate_db${RUBY_SUFFIX}.sh
	${INSTALL_SCRIPT} ${FILESDIR}/redmine_load_default_data.sh \
		${DESTDIR}${PREFIX}/bin/redmine61_load_default_data${RUBY_SUFFIX}.sh
	${INSTALL_DATA} ${FILESDIR}/README-pkgsrc ${DESTDIR}${PREFIX}/${RM_DIR}

post-install: unicorn-post-install
	${FIND} ${DESTDIR}${PREFIX} -name '.*' -exec ${RM} -rf {} +
	${MV} ${DESTDIR}${PREFIX}/${RM_DIR}/config/configuration.yml.example \
		${DESTDIR}/${EGDIR}
	${MV} ${DESTDIR}${PREFIX}/${RM_DIR}/config/database.yml.example \
		${DESTDIR}/${EGDIR}
	${MV} ${DESTDIR}${PREFIX}/${RM_DIR}/config/additional_environment.rb.example \
		${DESTDIR}/${EGDIR}

.include "../../devel/ruby-redmine/redmine.mk"

# for older Ruby
.if ${RUBY_VER} < 34
DEPENDS+=	${RUBY_PKGPREFIX}-csv>=3.3.2<3.4:../../textproc/ruby-csv
DEPENDS+=	${RUBY_PKGPREFIX}-net-imap>=0.5.7:../../net/ruby-net-imap
.  if ${RUBY_VER} < 33
DEPENDS+=	${RUBY_PKGPREFIX}-net-smtp>=0.5.1:../../net/ruby-net-smtp
.  endif
.endif

.include "options.mk"
.include "../../lang/ruby/modules.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"

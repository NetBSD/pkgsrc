# $NetBSD: Makefile,v 1.2 2025/01/20 14:29:19 taca Exp $

DISTNAME=	redmine-${RM_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/redmine/redmine${RM_VER}/}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://www.redmine.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.redmine.org/
COMMENT=	Flexible project management web application
LICENSE=	gnu-gpl-v2 # and so on.

RM_VERSION=	6.0.2

NO_BUILD=	yes

USE_LANGUAGES=	# none

RUBY_VERSIONS_ACCEPTED=	31 32 33
RUBY_RAILS_ACCEPTED=	72

PYTHON_VERSIONS_INCOMPATIBLE=	27

OVERRIDE_GEMSPEC+=	mini-magick>=4.11.0 nokogiri>=1.13.4

#DEPENDS+=	${RUBY_PKGPREFIX}-bundler>=1.12.0:../../misc/ruby-bundler
DEPENDS+=	${RUBY_RAILS_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-rouge>=4.5.0<5:../../www/ruby-rouge

# ruby-mail depends it.
#DEPENDS+=	${RUBY_PKGPREFIX}-mini_mime>=1.1.0<1.2:../../mail/ruby-mini_mime
DEPENDS+=	${RUBY_PKGPREFIX}-actionpack${RUBY_RAILS}-xml_parser>=2.0:../../textproc/ruby-actionpack-xml_parser
DEPENDS+=	${RUBY_PKGPREFIX}-roadie-rails${RUBY_RAILS}>=3.2.0<3.3:../../mail/ruby-roadie-rails
DEPENDS+=	${RUBY_PKGPREFIX}-marcel>=1.0.0:../../devel/ruby-marcel
DEPENDS+=	${RUBY_PKGPREFIX}-mail>=2.8.1<2.9:../../mail/ruby-mail
DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.16<2:../../textproc/ruby-nokogiri
DEPENDS+=	${RUBY_PKGPREFIX}-i18n>=1.14.1:../../devel/ruby-i18n
DEPENDS+=	${RUBY_PKGPREFIX}-rbpdf>=1.21.3<1.22:../../print/ruby-rbpdf
DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=0:../../net/ruby-addressable
DEPENDS+=	${RUBY_PKGPREFIX}-zip>=2.3.0<2.4:../../archivers/ruby-zip
DEPENDS+=	${RUBY_PKGPREFIX}-rotp>=6.2.0:../../security/ruby-rotp
DEPENDS+=	${RUBY_PKGPREFIX}-rqrcode>=1.2.0:../../textproc/ruby-rqrcode
DEPENDS+=	${RUBY_PKGPREFIX}-net-ldap>=0.17.0:../../net/ruby-net-ldap
DEPENDS+=	${RUBY_PKGPREFIX}-mini-magick>=5.0.1<6:../../graphics/ruby-mini-magick
DEPENDS+=	${RUBY_PKGPREFIX}-deckar01-task_list>=2.3.2:../../textproc/ruby-deckar01-task_list
DEPENDS+=	${RUBY_PKGPREFIX}-html-pipeline>=2.13.2<3:../../textproc/ruby-html-pipeline
DEPENDS+=	${RUBY_PKGPREFIX}-commonmarker>=0.23.8<1:../../textproc/ruby-commonmarker
DEPENDS+=	${RUBY_PKGPREFIX}-sanitize>=6.0<7:../../textproc/ruby-sanitize

.include "../../lang/ruby/modules.mk"

# not for ruby33
.if ${RUBY_VER} < 33
DEPENDS+=	${RUBY_PKGPREFIX}-csv>=3.2.8<4:../../textproc/ruby-csv
DEPENDS+=	${RUBY_PKGPREFIX}-net-imap>=0.4.8:../../net/ruby-net-imap
.  if ${RUBY_VER} < 32
DEPENDS+=	${RUBY_PKGPREFIX}-net-pop>=0.1.2:../../net/ruby-net-pop
DEPENDS+=	${RUBY_PKGPREFIX}-net-smtp>=0.3.3:../../net/ruby-net-smtp
.  endif
.endif

.include "options.mk"

REPLACE_RUBY+=	${DISTNAME}/bin/*
REPLACE_RUBY+=	${DISTNAME}/extra/mail_handler/rdm-mailhandler.rb
REPLACE_RUBY+=	${DISTNAME}/extra/svn/reposman.rb
REPLACE_RUBY+=	${DISTNAME}/public/dispatch.fcgi.example

SUBST_CLASSES+=		shell
SUBST_FILES.shell=	${DESTDIR}${PREFIX}/bin/redmine60_*${RUBY_SUFFIX}.sh
SUBST_MESSAGE.shell=	Fixing paths in helper shell scripts.
SUBST_VARS.shell=	PREFIX RUBY RM_DIR
SUBST_STAGE.shell=	post-install

EGDIR=		${PREFIX}/share/examples/${RUBY_PKGPREFIX}-redmine60
INSTALLATION_DIRS=	bin ${EGDIR} ${RM_DIR} ${RM_DIR}/config

CONF_FILES+=	${EGDIR}/configuration.yml.example \
			${RM_DIR}/config/configuration.yml
CONF_FILES+=	${EGDIR}/database.yml.example \
			${RM_DIR}/config/database.yml
CONF_FILES+=	${EGDIR}/additional_environment.rb.example \
			${RM_DIR}/config/additional_environment.rb
REQD_FILES+=	/dev/null ${RM_DIR}/Gemfile.lock

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
	${INSTALL_SCRIPT} ${FILESDIR}/redmine60_migrate_plugins.sh \
		${DESTDIR}${PREFIX}/bin/redmine60_migrate_plugins${RUBY_SUFFIX}.sh
	${INSTALL_SCRIPT} ${FILESDIR}/redmine60_generate_secret_token.sh \
		${DESTDIR}${PREFIX}/bin/redmine60_generate_secret_token${RUBY_SUFFIX}.sh
	${INSTALL_SCRIPT} ${FILESDIR}/redmine60_migrate_db.sh \
		${DESTDIR}${PREFIX}/bin/redmine60_migrate_db${RUBY_SUFFIX}.sh
	${INSTALL_SCRIPT} ${FILESDIR}/redmine60_load_default_data.sh \
		${DESTDIR}${PREFIX}/bin/redmine60_load_default_data${RUBY_SUFFIX}.sh

post-install: unicorn-post-install
	${FIND} ${DESTDIR}${PREFIX} -name '.*' -exec ${RM} -rf {} +
	${MV} ${DESTDIR}${PREFIX}/${RM_DIR}/config/configuration.yml.example \
		${DESTDIR}/${EGDIR}
	${MV} ${DESTDIR}${PREFIX}/${RM_DIR}/config/database.yml.example \
		${DESTDIR}/${EGDIR}
	${MV} ${DESTDIR}${PREFIX}/${RM_DIR}/config/additional_environment.rb.example \
		${DESTDIR}/${EGDIR}

.include "../../devel/ruby-redmine/redmine.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"

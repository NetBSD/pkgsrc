# $NetBSD: Makefile,v 1.4 2023/11/13 16:34:02 taca Exp $

DISTNAME=	icingaweb2-2.8.2
PKGREVISION=	1
GITHUB_TAG=	v${PKGVERSION_NOREV}
MASTER_SITES=	${MASTER_SITE_GITHUB:=icinga/}
CATEGORIES=	net sysutils www

MAINTAINER=	ef@math.uni-bonn.de
HOMEPAGE=	https://github.com/Icinga/icingaweb2
COMMENT=	PHP-based Web UI for Icinga
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PHP_PKG_PREFIX}-curl-[0-9]*:../../www/php-curl
DEPENDS+=	${PHP_PKG_PREFIX}-gd-[0-9]*:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-gettext-[0-9]*:../../devel/php-gettext
DEPENDS+=	${PHP_PKG_PREFIX}-imagick-[0-9]*:../../graphics/php-imagick
DEPENDS+=	${PHP_PKG_PREFIX}-intl-[0-9]*:../../textproc/php-intl
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring-[0-9]*:../../converters/php-mbstring
# For php-*sql see options.mk

USE_TOOLS+=	pax

USE_LANGUAGES=	# empty
NO_BUILD=	YES

# Can't set NO_CONFIGURE=YES since REPLACE_INTERPRETER needs a configure phase
do-configure:

PKG_SYSCONFSUBDIR=		icingaweb2
EGDIR=				${PREFIX}/share/examples/icingaweb2
SHAREDIR=			${PREFIX}/share/icingaweb2
INCDIR=				${PREFIX}/lib/php
INSTALLATION_DIRS+=		${PREFIX}/bin ${EGDIR} ${SHAREDIR}
STORAGEDIR=			${VARBASE}/db/icingaweb2
LOGDIR=				${VARBASE}/log/icingaweb2
OWN_DIRS+=			${STORAGEDIR} ${LOGDIR}
RUNDIR_PARENT=			${VARBASE}/run
EDITOR=				vi
PKG_SYSCONFDIR.icinga2?=	${PKG_SYSCONFBASE}/icinga2

BUILD_DEFS+=	VARBASE PKG_SYSCONFBASE

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

# The upstream distribution is not exactly packaging-friendly. It's kind of a blob, no Makefile, no configuration, everything-is-Linux mindset. Hard-coded paths everywhere, #!/usr/bin/env etc.
# Debian (upstream's main target) splits it into a bunch of packages, namely icingaweb2, icingaweb2-common, icingaweb2-module-doc, icingaweb2-module-monitoring (no -module-translation, that's in -common), icingacli (no "web" or "2") and php-icinga (also no "web" or "2").
# Most files go to /usr/share/icingaweb2, but to make it even more interesting, files in the php-icinga package are relocated from the library/Icinga subdiretory of the distribution to /usr/share/php/Icinga (but other files in that package go to /usr/share/icingaweb2/library).
# Some files aren't even installed at all.
# There are also no example configuration files.

# Install example configuration files.
# Contents taken from the "Advanced Topics: Icinga Web 2 Manual Setup: Icinga Web 2 Manual Configuration" manual section
CONFS=		roles.ini resources.ini config.ini authentication.ini groups.ini roles.ini
CONFDIRS=	modules modules/monitoring
CONFS+=		modules/monitoring/config.ini modules/monitoring/backends.ini modules/monitoring/commandtransports.ini
CONFDIRS+=	enabledModules
# symlinks in enabledModules?

# for extraction, see post-extract below

SUBST_CLASSES+=			sampleconfig-db
SUBST_STAGE.sampleconfig-db=	pre-configure
SUBST_MESSAGE.sampleconfig-db=	Fixing DB in config examples.
SUBST_FILES.sampleconfig-db=	etc/examples/resources.ini
# If compiled with MySQL support, use MySQL example, else PgSQL.
.if !empty(PKG_OPTIONS:Mmysql)
SUBST_SED.sampleconfig-db=	-e 's,@DB_TYPE@,mysql,g'
SUBST_SED.sampleconfig-db+=	-e 's,@DB_PORT@,3306,g'
.else
SUBST_SED.sampleconfig-db=	-e 's,@DB_TYPE@,pgsql,g'
SUBST_SED.sampleconfig-db+=	-e 's,@DB_PORT@,5432,g'
.endif

SUBST_CLASSES+=				sampleconfig-path
SUBST_STAGE.sampleconfig-path=		pre-configure
SUBST_MESSAGE.sampleconfig-path=	Fixing paths in config examples.
SUBST_FILES.sampleconfig-path=		etc/examples/config.ini
SUBST_VARS.sampleconfig-path=		SHAREDIR LOGDIR

# for installation of the example configuration files, see do-install below

.for d in ${CONFDIRS}
OWN_DIRS+=	${PKG_SYSCONFDIR}/${d}
.endfor

.for f in ${CONFS}
CONF_FILES+=	${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor


# Remove unneeded files in directories that are installed
RMFILES=	application/fonts/fontello-ifont/config.json application/fonts/fontello-ifont/demo.html
RMFILES+=	application/fonts/fontello-ifont/font/ifont.eot application/fonts/fontello-ifont/font/ifont.svg application/fonts/fontello-ifont/font/ifont.ttf application/fonts/fontello-ifont/font/ifont.woff application/fonts/fontello-ifont/font/ifont.woff2
RMFILES+=	application/fonts/fontello-ifont/LICENSE.txt application/fonts/fontello-ifont/README.txt
RMFILES+=	application/fonts/icingaweb.md
RMFILES+=	application/VERSION
RMFILES+=	library/vendor/dompdf/lib/php-font-lib/LICENSE
RMFILES+=	library/vendor/dompdf/LICENSE library/vendor/dompdf/SOURCE
RMFILES+=	library/vendor/HTMLPurifier/LICENSE library/vendor/HTMLPurifier/SOURCE
RMFILES+=	library/vendor/JShrink/LICENSE library/vendor/JShrink/SOURCE
RMFILES+=	library/vendor/lessphp/LICENSE library/vendor/lessphp/SOURCE
RMFILES+=	library/vendor/Parsedown/LICENSE library/vendor/Parsedown/SOURCE
RMFILES+=	library/vendor/Zend/LICENSE.txt library/vendor/Zend/README.md library/vendor/Zend/VERSION

# for actual removal, see post-extract below


# Some file have the executable bit set, but shouldn't
NONEXECFILES=	application/fonts/fontello-ifont/css/*
NONEXECFILES+=	public/font/*
NONEXECFILES+=	library/vendor/HTMLPurifier/DefinitionCache/Serializer/README

# for actual chmod, see post-extract below


REPLACE_SH=		test/setup_vendor.sh		# !/usr/bin/bash, no bashisms (not actually installed)
REPLACE_SH+=		test/travis_database.sh		# !/usr/bin/bash, no bashisms (not actually installed)

REPLACE_INTERPRETER+=	php
REPLACE.php.old=	.*php				# /usr/bin/php, /usr/bin/env php
REPLACE.php.new=	${PREFIX}/bin/php
REPLACE_FILES.php=	packages/files/bin/icingacli	# /usr/bin/php
REPLACE_FILES.php+=	test/check-syntax.php		# /usr/bin/env php (but not actually installed)

# We need a lot of SUBSTs. The list of hard-coded paths was gathered along the lines of "grep -rF '/etc/' . | sed -n -e 's:^.*/etc/\([^/]*\)/.*$:\1:p' | sort | uniq" etc., plus manual inspection.
# See below for a descrption what is NOT substituted.

SUBST_CLASSES+=			schema
SUBST_STAGE.schema=		pre-configure
SUBST_MESSAGE.schema=		Fixing schema paths.
SUBST_FILES.schema=		doc/20-Advanced-Topics.md
SUBST_FILES.schema+=		doc/80-Upgrading.md
SUBST_SED.schema=		-e 's,/usr/share/doc/icingaweb2,${SHAREDIR}/etc,g'

SUBST_CLASSES+=			sharedir
SUBST_STAGE.sharedir=		pre-configure
SUBST_MESSAGE.sharedir=		Fixing SHAREDIR paths.
SUBST_FILES.sharedir=		doc/03-Configuration.md
SUBST_FILES.sharedir+=		doc/20-Advanced-Topics.md
SUBST_FILES.sharedir+=		modules/setup/application/clicommands/ConfigCommand.php
SUBST_FILES.sharedir+=		public/error_unavailable.html
SUBST_FILES.sharedir+=		packages/files/bin/icingacli
SUBST_SED.sharedir=		-e 's,/usr/share/icingaweb2,${SHAREDIR},g'

SUBST_CLASSES+=			storagedir
SUBST_STAGE.storagedir=		pre-configure
SUBST_MESSAGE.storagedir=	Fixing STORAGEDIR paths.
SUBST_FILES.storagedir=		library/Icinga/Application/ApplicationBootstrap.php
SUBST_SED.storagedir=		-e 's,/var/lib/icingaweb2,${STORAGEDIR},g'

.if ${LOGDIR} != "/var/log/icingaweb2"
SUBST_CLASSES+=			logdir
SUBST_STAGE.logdir=		pre-configure
SUBST_MESSAGE.logdir=		Fixing LOGDIR paths.
SUBST_FILES.logdir=		application/forms/Config/General/LoggingConfigForm.php
SUBST_SED.logdir=		-e 's,/var/log/icingaweb2,${LOGDIR},g'
.endif

.if ${RUNDIR_PARENT} != "/var/run"
SUBST_CLASSES+=			rundir
SUBST_STAGE.rundir=		pre-configure
SUBST_MESSAGE.rundir=		Fixing RUNDIR paths.
SUBST_FILES.rundir=		doc/04-Resources.md
SUBST_FILES.rundir+=		modules/monitoring/application/forms/Config/Transport/LocalTransportForm.php
SUBST_FILES.rundir+=		modules/monitoring/application/forms/Config/Transport/RemoteTransportForm.php
SUBST_FILES.rundir+=		modules/monitoring/doc/05-Command-Transports.md
SUBST_FILES.rundir+=		modules/setup/application/clicommands/ConfigCommand.php
SUBST_SED.rundir=		-e 's,/var/run,${RUNDIR_PARENT},g'
.endif

# This is kind of gross, but occurs only in documentation and the setup tool
SUBST_CLASSES+=			apache2
SUBST_STAGE.apache2=		pre-configure
SUBST_MESSAGE.apache2=		Fixing Apache2 config paths.
SUBST_FILES.apache2=		doc/02-Installation.md
SUBST_FILES.apache2+=		doc/20-Advanced-Topics.md
SUBST_FILES.apache2+=		modules/setup/application/clicommands/ConfigCommand.php
SUBST_SED.apache2=		-e 's,/etc/apache2,${PREFIX}/etc/httpd,g'
SUBST_SED.apache2+=		-e 's,/etc/httpd,${PREFIX}/etc/httpd,g'

SUBST_CLASSES+=			icinga2
SUBST_STAGE.icinga2=		pre-configure
SUBST_MESSAGE.icinga2=		Fixing Icinga2 config paths.
SUBST_FILES.icinga2=		modules/monitoring/doc/05-Command-Transports.md
SUBST_SED.icinga2=		-e 's,/etc/icinga2,${PKG_SYSCONFDIR.icinga2},g'

SUBST_CLASSES+=			confdir
SUBST_STAGE.confdir=		pre-configure
SUBST_MESSAGE.confdir=		Fixing config paths.
SUBST_FILES.confdir=		doc/03-Configuration.md
SUBST_FILES.confdir+=		doc/04-Resources.md
SUBST_FILES.confdir+=		doc/05-Authentication.md
SUBST_FILES.confdir+=		doc/06-Security.md
SUBST_FILES.confdir+=		doc/07-Preferences.md
SUBST_FILES.confdir+=		doc/20-Advanced-Topics.md
SUBST_FILES.confdir+=		doc/90-SELinux.md
SUBST_FILES.confdir+=		library/Icinga/Application/ApplicationBootstrap.php
SUBST_FILES.confdir+=		modules/monitoring/doc/03-Configuration.md
SUBST_FILES.confdir+=		modules/monitoring/doc/05-Command-Transports.md
SUBST_FILES.confdir+=		modules/setup/application/clicommands/ConfigCommand.php
SUBST_FILES.confdir+=		modules/setup/application/clicommands/TokenCommand.php
#SUBST_FILES.confdir+=		modules/setup/application/locale/de_DE/LC_MESSAGES/setup.mo
SUBST_FILES.confdir+=		modules/setup/application/locale/de_DE/LC_MESSAGES/setup.po
#SUBST_FILES.confdir+=		modules/setup/application/locale/it_IT/LC_MESSAGES/setup.mo
SUBST_FILES.confdir+=		modules/setup/application/locale/it_IT/LC_MESSAGES/setup.po
SUBST_FILES.confdir+=		modules/setup/application/views/scripts/form/setup-welcome.phtml
SUBST_FILES.confdir+=		modules/setup/library/Setup/WebWizard.php
SUBST_SED.confdir=		-e 's,/etc/icingaweb2,${PKG_SYSCONFDIR},g'

SUBST_CLASSES+=			php-inc
SUBST_STAGE.php-inc=		pre-configure
SUBST_MESSAGE.php-inc=		Fixing PHP include paths.
SUBST_FILES.php-inc=		packages/files/bin/icingacli
SUBST_FILES.php-inc+=		packages/files/public/index.php
SUBST_SED.php-inc=		-e 's,/usr/share/php,${INCDIR},g'

# This is also kind of gross, but occurs only in documentation
SUBST_CLASSES+=			php-config
SUBST_STAGE.php-config=		pre-configure
SUBST_MESSAGE.php-config=	Fixing PHP config paths.
SUBST_FILES.php-config=		doc/02-Installation.md
SUBST_SED.php-config=		-e 's,/etc/php\.ini,${PREFIX}/etc/php.ini,g'
SUBST_SED.php-config+=		-e 's,/etc/php\.d,${PREFIX}/etc/php.d,g'

# These could be based on a "translation" option. It's used for msgformat, msgmerge and xgettext
SUBST_CLASSES+=			env-gettext
SUBST_STAGE.env-gettext=	pre-configure
SUBST_MESSAGE.env-gettext=	Fixing env usage.
SUBST_FILES.env-gettext=	modules/translation/library/Translation/Util/GettextTranslationHelper.php
SUBST_SED.env-gettext=		-e 's,/usr/bin/env ,${PREFIX}/bin/,g'

# While there, we can fix references to vim, too
SUBST_CLASSES+=			vim
SUBST_STAGE.vim=		pre-configure
SUBST_MESSAGE.vim=		Fixing vim references.
SUBST_FILES.vim=		doc/05-Authentication.md
SUBST_FILES.vim+=		doc/06-Security.md
SUBST_FILES.vim+=		doc/20-Advanced-Topics.md
SUBST_FILES.vim+=		modules/monitoring/doc/03-Configuration.md
SUBST_FILES.vim+=		modules/monitoring/doc/05-Command-Transports.md
SUBST_SED.vim=			-e 's,vim /,${EDITOR} /,g'

# There is also a bunch of hard-coded paths that are NOT substituted:
# -- comments at the head of .po files
# -- paths in files that are not actually installed: /usr/bin/msgfmt, /usr/bin/msgmerge, /usr/bin/xgettext, /usr/share/php, /var/lib/pgsql
# -- paths that are Linux-specific enyway: /usr/sbin/semodule, /usr/lib/os-release, /usr/share/selinux, /etc/apk, /etc/apt, /etc/audit, /etc/opt, /etc/selinux
# -- paths where the usage seems OK: /usr/share/{file,misc,mime}/magic{,.mime,.mgc}, /tmp, /proc/self
# -- example path in comment: /var/spool/whatwever

# post-extract jobs
post-extract:
	${MKDIR} ${WRKSRC}/etc/examples
.for d in ${CONFDIRS}
	${MKDIR} ${WRKSRC}/etc/examples/${d}
.endfor
.for f in ${CONFS}
	${CP} ${FILESDIR}/${f} ${WRKSRC}/etc/examples/${f}
.endfor
.for f in ${RMFILES}
	${RM} ${WRKSRC}/${f}
.endfor
.for f in ${NONEXECFILES}
	${CHMOD} -x ${WRKSRC}/${f}
.endfor

# Remove .orig file so it doesn't get installed
post-patch:
	${RM} ${WRKSRC}/library/Icinga/Application/webrouter.php.orig

# Install the files
do-install:
	cd ${WRKSRC} && ${PAX} -rw -pmp application doc etc/schema library/vendor modules/doc modules/migrate modules/monitoring modules/setup modules/translation modules/test public test ${DESTDIR}${SHAREDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/packages/files/public/index.php ${DESTDIR}${SHAREDIR}/public/index.php
	cd ${WRKSRC}/library && ${PAX} -rw -pmp Icinga ${DESTDIR}${INCDIR}
	cd ${WRKSRC}/etc/examples && ${PAX} -rw -pmp . ${DESTDIR}${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/packages/files/bin/icingacli ${DESTDIR}${PREFIX}/bin/icingacli

PLIST_SUBST+=	SHAREDIR="${SHAREDIR:S.${PREFIX}/..}"
PLIST_SUBST+=	INCDIR="${INCDIR:S.${PREFIX}/..}"
PLIST_SUBST+=	EGDIR="${EGDIR:S.${PREFIX}/..}"

GENERATE_PLIST+=	printf "${EGDIR:S.${PREFIX}/..}/%s\n" ${CONFS};

.include "../../lang/php/json.mk"
.include "../../mk/bsd.pkg.mk"

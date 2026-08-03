# $NetBSD: Makefile,v 1.106 2026/08/03 15:14:03 gdt Exp $

# This is a twisty maze of variables.  The plan is to edit VERSION
# (the zoneminder version) on upgrades, and have everything flow from
# there.
VERSION=	1.38.3
# Distfile is ZoneMinder but package and tarball contents are zoneminder.
NAME_DIST=	ZoneMinder
NAME_LOWER=	zoneminder
PKGNAME=	${DISTNAME:S/${NAME_DIST}-/${NAME_LOWER}-/}
PKGREVISION=	2
DISTNAME=	${NAME_DIST}-${VERSION}
WRKSRC=		${WRKDIR}/${NAME_LOWER}-${GITHUB_TAG}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=${NAME_DIST}/}
GITHUB_PROJECT=	${NAME_DIST}
GITHUB_TYPE=	tag
GITHUB_TAG=	${VERSION}

## Submodules (from ZoneMinder's .gitmodules file)
# We use a specific commit on each branch, to avoid distfile versioning woes
# and to meet pkgsrc expectations that a fixed version is fixed software.
# Upstream checks in submodules but this is not apparent in git tarballs.
#   https://github.com/ZoneMinder/zoneminder/issues/5010
# Check for updates every release.
GITHUB_SUBMODULES+=	FriendsOfCake crud 14292374ccf1328f2d5db20897bd06f99ba4d938 web/api/app/Plugin/Crud
GITHUB_SUBMODULES+=	ZoneMinder CakePHP-Enum-Behavior ea90c0cd7f6e24333a90885e563b5d30b793db29 web/api/app/Plugin/CakePHP-Enum-Behavior
GITHUB_SUBMODULES+=	ZoneMinder RtspServer a071599575f60a6f1f424e1f9b408dad7da734a8 dep/RtspServer
GITHUB_SUBMODULES+=	chmike CxxUrl eaf46c0207df24853a238d4499e7f4426d9d234c dep/CxxUrl

MAINTAINER=	dsainty@NetBSD.org
#MAINTAINER+=	gdt@NetBSD.org
HOMEPAGE=	https://www.zoneminder.com/
COMMENT=	Video camera security and surveillance solution
LICENSE=	gnu-gpl-v2

# ZoneMinder without a web server does not really make sense.  Require
# a webserver (until someone wanting to not have one provides
# rationale and a patch).
PKG_OPTIONS_VAR=		PKG_OPTIONS.zoneminder
PKG_OPTIONS_REQUIRED_GROUPS=	webserver
PKG_OPTIONS_GROUP.webserver=	apache nginx
PKG_SUGGESTED_OPTIONS=		apache

# ZoneMinder requires a database, historically mysql only.  This
# package supports mysql and MariaDB, which must be handled separately
# because p5-DBD-mysql is (2026-01) mysql only, with p5-DBD-MariaDB
# for MariaDB.
#   https://github.com/ZoneMinder/zoneminder/issues/5008
PKG_OPTIONS_REQUIRED_GROUPS+=	database
PKG_OPTIONS_GROUP.database=	mysql mariadb
PKG_SUGGESTED_OPTIONS+=		mariadb

.include "../../mk/bsd.options.mk"

## NOTES

# ZoneMinder discourages building from source and does not appear to
# document the list of dependencies.  We take the view that if an
# installation can be reasonably configured to use a module, that
# module should be a dependency, absent some reason that it is so
# heavyweight that it should be an option.

## MAIN BUILD

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake perl pkg-config

# Previously, we open-coded zm as a subdir of PKG_SYSCONFSUBDIR.  But
# lang/php/phpversion.mk (arguably wrongly) sets PKG_SYSCONFSUBDIR to
# a php location, leading to zoneminder looking for config in the
# wrong place.
PKG_SYSCONFSUBDIR=	zm

# Place man pages following pkgsrc norms, rather than share/man.
CMAKE_CONFIGURE_ARGS+=	-DZM_MANPAGE_DEST_PREFIX=${PREFIX}/${PKGMANDIR}

# For now, lean to debugging.
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_VERBOSE_MAKEFILE=true
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Debug

## PATHS

# zoneminder has a dizzying array of variables for various paths.
# Consolidate the settings in an attempt to reduce confusion.

# ZoneMinder prefers a subdirectory of etc.  Further, it demands a
# conf.d subdirectory within its config directory, which would be
# irregular at top level.
CMAKE_CONFIGURE_ARGS+=	-DZM_CONFIG_DIR=${PKG_SYSCONFDIR}
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR} ${REAL_ROOT_USER} ${APACHE_GROUP} 775
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/conf.d ${REAL_ROOT_USER} ${APACHE_GROUP} 775

ZM_HTTPD_ROOT=		share/zoneminder/htdocs
CMAKE_CONFIGURE_ARGS+=	-DZM_WEBDIR=${PREFIX}/${ZM_HTTPD_ROOT:Q}
PLIST_SUBST+=		ZM_HTTPD_ROOT=${ZM_HTTPD_ROOT:Q}
PRINT_PLIST_AWK+=	{ gsub(/${ZM_HTTPD_ROOT:S|/|\\/|g}/, "$${ZM_HTTPD_ROOT}") }
OWN_DIRS+=		${ZM_HTTPD_ROOT:Q}
INSTALLATION_DIRS+=	share/zoneminder ${ZM_HTTPD_ROOT}

ZM_HTTPD_CGIBIN=	libexec/zoneminder/cgi-bin
CMAKE_CONFIGURE_ARGS+=	-DZM_CGIDIR=${PREFIX}/${ZM_HTTPD_CGIBIN:Q}
PLIST_SUBST+=		ZM_HTTPD_CGIBIN=${ZM_HTTPD_CGIBIN:Q}
PRINT_PLIST_AWK+=	{ gsub(/${ZM_HTTPD_CGIBIN:S|/|\\/|g}/, "$${ZM_HTTPD_CGIBIN}") }
BUILD_DEFS+=		ZM_HTTPD_CGIBIN
OWN_DIRS+=		${ZM_HTTPD_CGIBIN:Q}
INSTALLATION_DIRS+=	libexec/zoneminder ${ZM_HTTPD_CGIBIN}

BUILD_DEFS+=		VARBASE
CMAKE_CONFIGURE_ARGS+=	-DZM_RUNDIR=${VARBASE}/run/zm
OWN_DIRS_PERMS+=	${VARBASE}/run/zm ${REAL_ROOT_USER} ${APACHE_GROUP} 775

# NB: Startup script must create /var/run/zm.
CMAKE_CONFIGURE_ARGS+=	-DZM_SOCKDIR=${VARBASE}/run/zm

CMAKE_CONFIGURE_ARGS+=	-DZM_TMPDIR=${VARBASE}/tmp/zm
OWN_DIRS_PERMS+=	${VARBASE}/tmp/zm ${REAL_ROOT_USER} ${APACHE_GROUP} 775

# Probably, one can configure logging to ZM_LOGDIR.
CMAKE_CONFIGURE_ARGS+=	-DZM_LOGDIR=${VARBASE}/log/zm
OWN_DIRS_PERMS+=	${VARBASE}/log/zm ${REAL_ROOT_USER} ${APACHE_GROUP} 775

# Remediate cmake searching for rm in the build environment, finding
# tools wrappers, and assuming that is that way in the runtime environment.
CMAKE_CONFIGURE_ARGS+=	-DZM_PATH_RM=/bin/rm

# Choose directory where zoneminder can create shm files (for zmc).
# \todo Define this per-OS, perhaps hoisting to mk.
ZM_SHM=			/var/shm	# NetBSD
CMAKE_CONFIGURE_ARGS+=	-DZM_PATH_MAP=${ZM_SHM}

# Cache directory is for js files to be served.
ZM_CACHE=		${VARBASE}/cache/zoneminder
CMAKE_CONFIGURE_ARGS+=	-DZM_CACHEDIR=${ZM_CACHE}
OWN_DIRS_PERMS+=	${ZM_CACHE} ${APACHE_USER} ${APACHE_GROUP} 775

# Storage of events; this should persist and is hence in /var/db.
ZM_CONTENT=		${VARBASE}/db/zoneminder
CMAKE_CONFIGURE_ARGS+=	-DZM_CONTENTDIR=${ZM_CONTENT}
OWN_DIRS_PERMS+=	${ZM_CONTENT} ${REAL_ROOT_USER} ${APACHE_GROUP} 775
CMAKE_CONFIGURE_ARGS+=	-DZM_DIR_EVENTS=${ZM_CONTENT}/events
OWN_DIRS_PERMS+=	${ZM_CONTENT}/events ${APACHE_USER} ${APACHE_GROUP} 775

## Dependencies other than perl and php.

PTHREAD_AUTO_VARS=	yes
.include "../../mk/pthread.buildlink3.mk"

# \todo Move to higher ffmpeg.
.include "../../multimedia/ffmpeg6/buildlink3.mk"
.for lib in AVFORMAT AVCODEC AVDEVICE AVUTIL SWSCALE SWRESAMPLE
CMAKE_CONFIGURE_ARGS+=	-D${lib}_INCLUDE_DIR=${BUILDLINK_PREFIX.ffmpeg6}/include/ffmpeg6
CMAKE_CONFIGURE_ARGS+=	-D${lib}_LIBRARIES=${BUILDLINK_PREFIX.ffmpeg6}/lib/ffmpeg6/lib${lib:tl}.${SHLIB_EXT}
.endfor

# \todo Recheck if this is needed.
# MySQL uses openssl.  Force zoneminder not to choose otherwise by
# finding libraries that are present but not buildlinked.
CMAKE_CONFIGURE_ARGS+=	-DGNUTLS_LIBRARIES=""
CMAKE_CONFIGURE_ARGS+=	-DGCRYPT_LIBRARIES=""

# Darwin does have sendfile(), but the API differs from ZoneMinder's
# expectation.
# \todo Convert to cmake.
# CONFIGURE_ARGS.Darwin+=	ac_cv_func_sendfile=no ac_cv_header_sys_sendfile_h=no

# \todo Depend on execinfo, because cmake looks for it.

## PERL

PERL5_REQD+=		5.6.0

# zoneminder's build system will build modules, and there is far more
# than perl, so tell the perl module code not to take over the build.
PERL5_CONFIGURE=	no
.include "../../lang/perl5/module.mk"

# Override perl detection so proper perl path is in installed binaries.
CMAKE_CONFIGURE_ARGS+=	-DPERL_EXECUTABLE=${PREFIX}/bin/perl

# \todo Align perl dependencies to zoneminder 1.38 reality
# May be helpful or horrifying:
#   pkg_info -L zoneminder | egrep  \\.pm\$ | xargs cat | egrep '^use.*::' | egrep -v '(IO|ZoneMinder|ONVIF)::' | sed -e 's/ qw(.*)//' | sed -e 's/ base//' | sort | uniq -c

# perl modules form CMakeLists.txt, in order, either commented or
# DEPENDed on:
#   builtin?	Sys::Syslog
#   option	DBI/DBD
#		Getopt::Long
#		Time::HiRes
DEPENDS+=	p5-Date-Manip-[0-9]*:../../devel/p5-Date-Manip
#		LWP::UserAgent
#		ExtUtils::MakeMaker
DEPENDS+=	p5-Sys-Mmap-[0-9]*:../../devel/p5-Sys-Mmap

# Non-builtin perl modules referenced in installed .pm but not checked
# for by CMakeLists.txt:
DEPENDS+=	p5-Class-Std-Fast-[0-9]*:../../devel/p5-Class-Std-Fast
DEPENDS+=	p5-Data-Dump-[0-9]*:../../devel/p5-Data-Dump
DEPENDS+=	p5-Data-Dumper-[0-9]*:../../devel/p5-Data-Dumper
DEPENDS+=	p5-Data-UUID-[0-9]*:../../devel/p5-Data-UUID
# Date::format (p5-Time-Date)
DEPENDS+=	p5-Device-SerialPort-[0-9]*:../../comms/p5-Device-SerialPort
# HTTP::Cookies
# HTTP::Request
# MIME::Base64
DEPENDS+=	p5-SOAP-WSDL-[0-9]*:../../net/p5-SOAP-WSDL
# Scalar::Util
# Sys::Mmap
# Sys::Syslog
# Time::Local
# URI::Encode
# URI::Escape
DEPENDS+=	p5-XML-LibXML-[0-9]*:../../textproc/p5-XML-LibXML

# perl modules not referenced in installed .pm.  These are either
# inexplicably needed, or leftover from historical zoneminder
# packages.
# (Left for now; to be removed/addressed.)
DEPENDS+=	p5-Archive-Zip-[0-9]*:../../archivers/p5-Archive-Zip
DEPENDS+=	p5-Class-Std-[0-9]*:../../devel/p5-Class-Std
DEPENDS+=	p5-Data-Entropy-[0-9]*:../../devel/p5-Data-Entropy
DEPENDS+=	p5-Data-Float-[0-9]*:../../devel/p5-Data-Float
DEPENDS+=	p5-File-Slurp-[0-9]*:../../devel/p5-File-Slurp
DEPENDS+=	p5-PHP-Serialization-[0-9]*:../../devel/p5-PHP-Serialization
DEPENDS+=	p5-MIME-Lite-[0-9]*:../../mail/p5-MIME-Lite
DEPENDS+=	p5-MIME-tools-[0-9]*:../../mail/p5-MIME-tools
DEPENDS+=	p5-IO-Socket-Multicast-[0-9]*:../../net/p5-IO-Socket-Multicast
DEPENDS+=	p5-Net-SFTP-Foreign-[0-9]*:../../net/p5-Net-SFTP-Foreign
DEPENDS+=	p5-Crypt-Eksblowfish-[0-9]*:../../security/p5-Crypt-Eksblowfish
DEPENDS+=	p5-Sys-MemInfo-[0-9]*:../../sysutils/p5-Sys-MemInfo
DEPENDS+=	p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser
DEPENDS+=	p5-Number-Bytes-Human-[0-9]*:../../textproc/p5-Number-Bytes-Human
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

# A large subset of perl scripts set PATH explicitly and need to be patched.
# See "PATH FIXUPS" below.
# \todo Teach pkglint that this variable is a list.
ZM_PERL_PATH=	scripts/zmaudit.pl.in
ZM_PERL_PATH+=	scripts/zmcamtool.pl.in
ZM_PERL_PATH+=	scripts/zmcontrol.pl.in
ZM_PERL_PATH+=	scripts/zmdc.pl.in
ZM_PERL_PATH+=	scripts/zmfilter.pl.in
ZM_PERL_PATH+=	scripts/zmpkg.pl.in
ZM_PERL_PATH+=	scripts/zmstats.pl.in
ZM_PERL_PATH+=	scripts/zmtelemetry.pl.in
ZM_PERL_PATH+=	scripts/zmtrack.pl.in
ZM_PERL_PATH+=	scripts/zmtrigger.pl.in
ZM_PERL_PATH+=	scripts/zmupdate.pl.in
ZM_PERL_PATH+=	scripts/zmvideo.pl.in
ZM_PERL_PATH+=	scripts/zmwatch.pl.in
ZM_PERL_PATH+=	scripts/zmx10.pl.in

## DATABASE

# There is no reason to suspect that any MariaDB version in pkgsrc is
# problematic, but most have not been tested.
.if !empty(PKG_OPTIONS:Mmariadb)
# 2026-01: 1.36 works with mariadb 10.6 on NetBSD
# 2024-01: 1.36 works with mariadb 11.2 on GNU/Linux
# 2026-07: 1.38 works with mariadb 10.6 on NetBSD
DEPENDS+=			p5-DBD-MariaDB-[0-9]*:../../databases/p5-DBD-MariaDB
MYSQL_VERSIONS_ACCEPTED=	mariadb118 mariadb114 mariadb1011 mariadb106 mariadb105
CMAKE_CONFIGURE_ARGS+=		-DZM_DB_TYPE=MariaDB
.endif
.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=			p5-DBD-mysql-[0-9]*:../../databases/p5-DBD-mysql
MYSQL_VERSIONS_ACCEPTED=	80
CMAKE_CONFIGURE_ARGS+=		-DZM_DB_TYPE=mysql
# WARNING: Omit the mysql hunk in the CMakeLists patch, if wanting to
# use mysql, and feel free to send in a cleaner solution -- omitted
# for now because there appear to be zero mysql users.
.endif

.include "../../mk/mysql.buildlink3.mk"

## PHP

# php-apcu fails with 56, and there's no reason to think about 56.
# 20250103 1.36.37:
#   74 has not been tested recently, but there's no reason to try to use it.
#   81 has not been tested recently; probably it works.
#   82 and 83 work.
#   84 has not been tested, but FreeBSD ports seems to think it works.
# 202060729 1.38.2:
#   83 works
PHP_VERSIONS_INCOMPATIBLE=	56

.include "../../lang/php/phpversion.mk"
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_mysql>=${PHP_BASE_VERS}:../../databases/php-pdo_mysql
DEPENDS+=	${PHP_PKG_PREFIX}-sysvsem>=${PHP_BASE_VERS}:../../devel/php-sysvsem
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=${PHP_BASE_VERS}:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-sockets>=${PHP_BASE_VERS}:../../net/php-sockets
DEPENDS+=	${PHP_PKG_PREFIX}-intl>=${PHP_BASE_VERS}:../../textproc/php-intl
DEPENDS+=	${PHP_PKG_PREFIX}-apcu-[0-9]*:../../www/php-apcu

.include "../../lang/php/json.mk"

## WEB

# \todo We need to choose user/group, and somehow make this play well
# with apache, nginx, and php_fpm.  For now, assume that anyone using
# nginx/fpm will align that to APACHE_*, and treat the larger question
# as beyond scope.
PKG_USERS_VARS+=	APACHE_USER
PKG_GROUPS_VARS+=	APACHE_GROUP
BUILD_DEFS+=		APACHE_USER APACHE_GROUP

CMAKE_CONFIGURE_ARGS+=	-DZM_WEB_USER=${APACHE_USER}
CMAKE_CONFIGURE_ARGS+=	-DZM_WEB_GROUP=${APACHE_GROUP}

# We set ZM_PATH_ZMS to a zm-specific cgi-bin directory, so that
# enabling that in apache (or nginx) exposes nph-zms, and not whatever
# other random cgi scripts have been installed by other packages.
# This sets the path to be used, and httpd/nginx config must alias
# that path to $PREFIX/libexec/zoneminder/cgi-bin/.
# \todo Add a leading / to avoid cmake deciding to make it absolute by
# prepending workdir.
CMAKE_CONFIGURE_ARGS+=	-DZM_PATH_ZMS=/zm/cgi-bin/nph-zms

.if !empty(PKG_OPTIONS:Mapache)
.include "../../mk/apache.mk"
DEPENDS+=	${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}-[0-9]*:../../www/ap-php
.endif
.if !empty(PKG_OPTIONS:Mnginx)
# \todo Actually test this option.  Add an nginx config fragment to files/examples.
DEPENDS+=	nginx-[0-9]*:../../www/nginx
DEPENDS+=	${PHP_PKG_PREFIX}-fpm>=${PHP_BASE_VERS}:../../www/php-fpm
.endif

## PATH FIXUPS

# Remediate idiom in perl scripts to set PATH, by adding ${PREFIX}/bin.
# \todo Some scripts use zmconf to get a PATH and perhaps a change
# towards that should be filed upstream.
SUBST_CLASSES+=			script-path
SUBST_MESSAGE.script-path=	Adjusting paths in scripts.
SUBST_STAGE.script-path=	pre-configure
SUBST_FILES.script-path=	${ZM_PERL_PATH}
SUBST_SED.script-path=		-e "s|^\\([\$$]ENV{PATH} *= *'\\).*';\$$|\\1${PREFIX}/bin:/bin:/usr/bin';|g"

# Substitute configured path in pkgsrc-provided apache config.
SUBST_CLASSES+=		files
SUBST_STAGE.files=	pre-configure
SUBST_FILES.files=	httpd-zoneminder.conf
SUBST_SED.files=	-e "s|@ZM_HTTPD_ROOT@|${PREFIX}/${ZM_HTTPD_ROOT}|g"
SUBST_SED.files+=	-e "s|@ZM_HTTPD_CGIBIN@|${PREFIX}/${ZM_HTTPD_CGIBIN}|g"
SUBST_MESSAGE.files=	Setting paths in Apache configuration file.

## INIT SCRIPTS

# \todo This script appears Linuxy rather than written for
# NetBSD/pkgsrc-rcd.  Understand, and then adjust or replace.
PLIST_VARS+=		rcd

.if ${INIT_SYSTEM} == "rc.d"
PLIST.rcd=		yes
# \todo Hold installation until validated
#RCD_SCRIPTS+=		zoneminder
.endif
PRINT_PLIST_AWK+=	{ gsub(/^.+\/examples\/rc.d/, "$${PLIST.rcd}&"); }

## PKGSRC PHASE FIXUPS

# Copy the example config to WRKSRC because we SUBST it, and files/ should be read only.

post-extract:
	${CP} ${FILESDIR}/httpd-zoneminder.conf ${WRKSRC}/httpd-zoneminder.conf

# Omit patchfiles from PLIST if present.  The pre-configure step below
# should prevent this from being necessary.
PRINT_PLIST_AWK+=	/.orig$$/ { next; }

# After patching, remove .orig versions of .pm, because they are
# wrongly installed due to wildcard rules.
pre-configure:
	${FIND} ${WRKSRC} -name "*.pm*.orig" -type f | ${XARGS} ${RM} -f

EGDIR=			share/examples/${PKGBASE}
DOCDIR=			share/doc/${PKGBASE}
INSTALLATION_DIRS+=	${EGDIR} ${EGDIR}/config ${EGDIR}/config/conf.d ${EGDIR}/apache
CONF_FILES+=		${PREFIX}/${EGDIR}/config/zm.conf ${PKG_SYSCONFDIR}/zm.conf
CONF_FILES+=		${PREFIX}/${EGDIR}/config/conf.d/01-system-paths.conf ${PKG_SYSCONFDIR}/conf.d/01-system-paths.conf
CONF_FILES+=		${PREFIX}/${EGDIR}/config/conf.d/02-multiserver.conf ${PKG_SYSCONFDIR}/conf.d/02-multiserver.conf
CONF_FILES+=		${PREFIX}/${EGDIR}/config/conf.d/README ${PKG_SYSCONFDIR}/conf.d/README
INSTALLATION_DIRS+=	bin share/examples/rc.d share/zoneminder/db
INSTALLATION_DIRS+=	${DOCDIR}

post-install:
	# Remediate bundled deps installing things.
	${RM}		-rf ${DESTDIR}${PREFIX}/include/jwt-cpp
	${RM}		-rf ${DESTDIR}${PREFIX}/include/picojson
	${RM}		-rf ${DESTDIR}${PREFIX}/cmake
	${RM}		-rf ${DESTDIR}${PREFIX}/include/CxxUrl
	${RM}		-rf ${DESTDIR}${PREFIX}/lib/cmake
	${RM}		-f ${DESTDIR}${PREFIX}/lib/libCxxUrl.a
	${RMDIR}	${DESTDIR}${PREFIX}/include
	# Config files to EGDIR.
	${INSTALL_DATA} ${WRKSRC}/httpd-zoneminder.conf ${DESTDIR}${PREFIX}/${EGDIR}/apache/httpd-zoneminder.conf
	${INSTALL_DATA} ${WRKSRC}/${CMAKE_BUILD_DIR}/zm.conf ${DESTDIR}${PREFIX}/${EGDIR}/config/zm.conf
	${INSTALL_DATA} ${WRKSRC}/${CMAKE_BUILD_DIR}/conf.d/* ${DESTDIR}${PREFIX}/${EGDIR}/config/conf.d
	# rc.d to examples
.if ${INIT_SYSTEM} == "rc.d"
	${INSTALL_SCRIPT} ${WRKSRC}/${CMAKE_BUILD_DIR}/scripts/zm ${DESTDIR}${PREFIX}/share/examples/rc.d/zoneminder
.endif
	# Install SQL data files.   \todo Check and fix upstream.
	${INSTALL_DATA} ${WRKSRC}/db/*.sql ${DESTDIR}${PREFIX}/share/zoneminder/db/
	# Install pkgsrc README.
	${INSTALL_DATA} files/README-pkgsrc.md ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../devel/cmake/build.mk"

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
# \todo Consider graphics/libv4l.
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../net/libvncserver/buildlink3.mk"
.include "../../multimedia/mp4v2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

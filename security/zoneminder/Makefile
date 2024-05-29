# $NetBSD: Makefile,v 1.71 2024/05/29 16:34:21 adam Exp $

#VERSION=	1.36.7
VERSION=	1.30.5
PKGREVISION=	11
# Sometimes the distfile unpacks to ZoneMinder and sometimes zoneminder.
NAME_DIST=	ZoneMinder
NAME_LOWER=	zoneminder

PKGNAME=	${DISTNAME:S/${NAME_DIST}-/${NAME_LOWER}-/}
DISTNAME=	${NAME_DIST}-${VERSION}
WRKSRC=		${WRKDIR}/${NAME_LOWER}-${VERSION}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=${NAME_DIST}/}
GITHUB_PROJECT=	${NAME_DIST}
GITHUB_TYPE=	tag
GITHUB_TAG=	${PKGVERSION_NOREV}

# Submodules as per ZoneMinder's .gitmodules file
GITHUB_SUBMODULES=	FriendsOfCake crud v3.0.10 web/api/app/Plugin/Crud

MAINTAINER=	dsainty@NetBSD.org
#MAINTAINER+=	gdt@NetBSD.org
HOMEPAGE=	https://www.zoneminder.com/
COMMENT=	Video camera security and surveillance solution
LICENSE=	gnu-gpl-v2

# NetBSD tar: Invalid header, starting valid header search.
EXTRACT_USING=	gtar

# ZoneMinder 1.29.0 seems to work fine on at least PHP 5.6 and 7.4.
# Under PHP 8.0 it is logging at Error level type errors out of skin.js.
# Under PHP 8.1 it is logging at Panic level that strftime is deprecated.
PHP_VERSIONS_ACCEPTED=	56 74

PKG_OPTIONS_VAR=	PKG_OPTIONS.zoneminder
PKG_SUPPORTED_OPTIONS=	apache
PKG_SUGGESTED_OPTIONS=	apache

.include "../../mk/bsd.options.mk"

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake perl pkg-config

# zoneminder can depend on a number of perl modules depending on
# configuration.  We take the view that if an installation can be
# reasonably configured to use a module, that module should be a
# dependency, absent some reason that it is so heavyweight that it
# should be an option.

# MIME::Entity is needed from p5-MIME-tools
# LWP::UserAgent is needed from p5-libwww
DEPENDS+=	p5-Archive-Zip-[0-9]*:../../archivers/p5-Archive-Zip
DEPENDS+=	p5-Date-Manip-[0-9]*:../../devel/p5-Date-Manip
DEPENDS+=	p5-Device-SerialPort-[0-9]*:../../comms/p5-Device-SerialPort
DEPENDS+=	p5-DBD-mysql-[0-9]*:../../databases/p5-DBD-mysql
DEPENDS+=	p5-MIME-Lite-[0-9]*:../../mail/p5-MIME-Lite
DEPENDS+=	p5-MIME-tools-[0-9]*:../../mail/p5-MIME-tools
DEPENDS+=	p5-Net-SFTP-Foreign-[0-9]*:../../net/p5-Net-SFTP-Foreign
DEPENDS+=	p5-PHP-Serialization-[0-9]*:../../devel/p5-PHP-Serialization
DEPENDS+=	p5-Sys-Mmap-[0-9]*:../../devel/p5-Sys-Mmap
#DEPENDS+=	{perl>=5.7.3,p5-Time-HiRes-[0-9]*}:../../time/p5-Time-HiRes
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

# \todo: Decide to drop CONFIGURE_ARGS, validating that each has been
# turned into cmake, once we are at a zoneminder version that does not
# support autoconf (which maybe we are at already!).
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CMAKE_ARGS+=		-DZM_CONFIG_DIR=${PKG_SYSCONFDIR}

ZM_HTTPD_ROOT=		share/zoneminder/htdocs
PLIST_SUBST+=		ZM_HTTPD_ROOT=${ZM_HTTPD_ROOT:Q}
PRINT_PLIST_AWK+=	{ gsub(/${ZM_HTTPD_ROOT:S|/|\\/|g}/, "$${ZM_HTTPD_ROOT}") }
OWN_DIRS+=		${ZM_HTTPD_ROOT:Q}

ZM_HTTPD_CGIBIN=	libexec/zoneminder/cgi-bin
PLIST_SUBST+=		ZM_HTTPD_CGIBIN=${ZM_HTTPD_CGIBIN:Q}
PRINT_PLIST_AWK+=	{ gsub(/${ZM_HTTPD_CGIBIN:S|/|\\/|g}/, "$${ZM_HTTPD_CGIBIN}") }
BUILD_DEFS+=		ZM_HTTPD_CGIBIN
OWN_DIRS+=		${ZM_HTTPD_CGIBIN:Q}

INSTALLATION_DIRS+=	share/zoneminder ${ZM_HTTPD_ROOT}
INSTALLATION_DIRS+=	libexec/zoneminder ${ZM_HTTPD_CGIBIN}

BUILD_DEFS+=		VARBASE
CONFIGURE_ARGS+=	--with-webdir=${PREFIX}/${ZM_HTTPD_ROOT:Q}
CMAKE_ARGS+=		-DZM_WEBDIR=${PREFIX}/${ZM_HTTPD_ROOT:Q}
CONFIGURE_ARGS+=	--with-cgidir=${PREFIX}/${ZM_HTTPD_CGIBIN:Q}
CMAKE_ARGS+=		-DZM_CGIDIR=${PREFIX}/${ZM_HTTPD_CGIBIN:Q}
CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CMAKE_ARGS+=		-DZM_RUNDIR=${VARBASE}/run/zm
CMAKE_ARGS+=		-DZM_SOCKDIR=${VARBASE}/run/zm
CMAKE_ARGS+=		-DZM_TMPDIR=${VARBASE}/tmp/zm
CMAKE_ARGS+=		-DZM_LOGDIR=${VARBASE}/log/zm

# PolicyKit doesn't actually seem to be necessary.  This hack disables
# configure's hunt for PolicyKit, but has no other apparent ill effects.
# cmake needs an almost identical hack - though resorting to patching might
# be safer.
CONFIGURE_ENV+=		POLKIT_CFLAGS=" " POLKIT_LIBS=" "
CMAKE_ARGS+=		-DPOLKIT_LIBRARIES=" " -DPOLKIT_INCLUDE_DIR=" "

PTHREAD_AUTO_VARS=	yes
.include "../../mk/pthread.buildlink3.mk"

# This should probably be ffmpeg4 at least.  Defer until up-to-date.
.include "../../multimedia/ffmpeg2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ffmpeg=${BUILDLINK_PREFIX.ffmpeg2}
CONFIGURE_ENV+=		PATH_FFMPEG=${BUILDLINK_PREFIX.ffmpeg2}/bin/ffmpeg2
CONFIGURE_ENV+=		OPT_FFMPEG=yes

.if ${OPSYS} == "Darwin"
SOEXT=	dylib
.else
SOEXT=	so
.endif

.for lib in AVFORMAT AVCODEC AVDEVICE AVUTIL SWSCALE
CMAKE_ARGS+=	-D${lib}_INCLUDE_DIR=${BUILDLINK_PREFIX.ffmpeg2}/include/ffmpeg2
CMAKE_ARGS+=	-D${lib}_LIBRARIES=${BUILDLINK_PREFIX.ffmpeg2}/lib/ffmpeg2/lib${lib:tl}.${SOEXT}
.endfor

# The backtrace requires Linux's unportable <execinfo.h> header.
CONFIGURE_ARGS+=	--enable-crashtrace=no

# Need Perl Sys::Mmap module for (default) mmap support.
CONFIGURE_ARGS+=	--enable-mmap=no

# This is somewhat awkward.  ffmpeg's libavformat/avformat.h requires
# constant macros from stdint.h, but these are only defined under C++ if
# __STDC_CONSTANT_MACROS is requested, so we have to do that on behalf
# of ffmpeg.  Failure to do so causes configure time failures, and
# build failures complaining about UINT64_C not being defined.
CFLAGS+=		-D__STDC_CONSTANT_MACROS

# Since MySQL uses openssl, use the same library instead of defaulting to
# gnutls.
CONFIGURE_ENV+=		ZM_SSL_LIB=openssl
CMAKE_ARGS+=		-DGNUTLS_LIBRARIES=""

# Make sure cmake doesn't think libgcrypt is available (We have OpenSSL)
CMAKE_ARGS+=		-DGCRYPT_LIBRARIES=""

# Control where run-time state (PID file and sockets) get stored.
# Default is "/var/run/zm", but we want to conform to VARBASE.
CONFIGURE_ENV+=		ZM_RUNDIR=${VARBASE}/run/zm
CONFIGURE_ENV+=		ZM_SOCKDIR=${VARBASE}/run/zm

#
# Darwin does have sendfile(), but the API differs from ZoneMinder's
# expectation.
#
CONFIGURE_ARGS.Darwin+=	ac_cv_func_sendfile=no ac_cv_header_sys_sendfile_h=no

.if !empty(PKG_OPTIONS:Mapache)
.include "../../mk/apache.mk"

PKG_USERS_VARS+=	APACHE_USER
PKG_GROUPS_VARS+=	APACHE_GROUP
BUILD_DEFS+=		APACHE_USER APACHE_GROUP

# This directory contains no useful state, so use MAKE_DIRS instead of
# OWN_DIRS.
MAKE_DIRS_PERMS+=	${VARBASE}/run/zm ${REAL_ROOT_USER} ${APACHE_GROUP} 775

CONFIGURE_ARGS+=	--with-webuser=${APACHE_USER}
CMAKE_ARGS+=		-DZM_WEB_USER=${APACHE_USER}
CONFIGURE_ARGS+=	--with-webgroup=${APACHE_GROUP}
CMAKE_ARGS+=		-DZM_WEB_GROUP=${APACHE_GROUP}

# If we're using Apache we're going to need PHP, and PHP extensions.
.include "../../lang/php/phpversion.mk"
DEPENDS+=	${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}-[0-9]*:../../www/ap-php
DEPENDS+=	${PHP_PKG_PREFIX}-gd-[0-9]*:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_mysql-[0-9]*:../../databases/php-pdo_mysql
DEPENDS+=	${PHP_PKG_PREFIX}-sockets-[0-9]*:../../net/php-sockets
.endif

# \todo Somehow, this permission setup still fails.
# This directory contains state, so use OWN_DIRS instead of MAKE_DIRS.
ZM_CACHE=		${VARBASE}/cache/zoneminder
OWN_DIRS_PERMS+=	${ZM_CACHE} ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 755
OWN_DIRS_PERMS+=	${ZM_CACHE}/temp ${REAL_ROOT_USER} ${APACHE_GROUP} 775
OWN_DIRS_PERMS+=	${ZM_CACHE}/images ${REAL_ROOT_USER} ${APACHE_GROUP} 775
OWN_DIRS_PERMS+=	${ZM_CACHE}/events ${REAL_ROOT_USER} ${APACHE_GROUP} 775
CMAKE_ARGS+=		-DZM_CONTENTDIR=${ZM_CACHE}

# ZoneMinder scripts needing Perl $PATH patching AND interpreter patching
ZM_REPLACE_PERL+=	scripts/zmaudit.pl.in
ZM_REPLACE_PERL+=	scripts/zmcamtool.pl.in
ZM_REPLACE_PERL+=	scripts/zmcontrol.pl.in
ZM_REPLACE_PERL+=	scripts/zmdc.pl.in
ZM_REPLACE_PERL+=	scripts/zmfilter.pl.in
ZM_REPLACE_PERL+=	scripts/zmpkg.pl.in
ZM_REPLACE_PERL+=	scripts/zmtelemetry.pl.in
ZM_REPLACE_PERL+=	scripts/zmtrack.pl.in
ZM_REPLACE_PERL+=	scripts/zmtrigger.pl.in
ZM_REPLACE_PERL+=	scripts/zmupdate.pl.in
ZM_REPLACE_PERL+=	scripts/zmvideo.pl.in
ZM_REPLACE_PERL+=	scripts/zmwatch.pl.in
ZM_REPLACE_PERL+=	scripts/zmx10.pl.in

# ZoneMinder scripts needing interpreter patching
REPLACE_PERL+=	${ZM_REPLACE_PERL}
REPLACE_PERL+=	onvif/scripts/zmonvif-probe.pl
REPLACE_PERL+=	zmconfgen.pl.in

#
# The intention of zmsystemctl.pl is to use bin/pkexec to allow the
# apache user to start and stop the ZoneMinder services on operating
# systems using systemd and newer versions of Polkit than Pkgsrc
# currently has.
#
# If the base OS doesn't use systemd (E.g. anything not Linux), this
# file shouldn't be used anyway.
#
# In Pkgsrc we ignore the potentially absent pkexec interpreter in
# this file.  If the base OS uses systemd, it probably also has pkexec
# in its base installation.
#

CHECK_INTERPRETER_SKIP+=	bin/zmsystemctl.pl

SUBST_CLASSES+=			systemd-perl
SUBST_MESSAGE.systemd-perl=	Adjusting systemd pkexec perl.
SUBST_STAGE.systemd-perl=	pre-configure
SUBST_FILES.systemd-perl=	scripts/zmsystemctl.pl.in
SUBST_SED.systemd-perl=		-e 's|/usr/bin/perl|${PERL5}|g'

SUBST_CLASSES+=			dbpaths-path
SUBST_MESSAGE.dbpaths-path=	Adjusting default paths in configuration.
SUBST_STAGE.dbpaths-path=	pre-configure
SUBST_FILES.dbpaths-path=	db/zm_create.sql.in
SUBST_SED.dbpaths-path=		-e 's|/usr/local/bin/|${PREFIX}/bin/|g'
SUBST_SED.dbpaths-path+=	-e 's|/usr/bin|${PREFIX}/bin|g'
SUBST_SED.dbpaths-path+=	-e 's|/cgi-bin/nph-zms|/zm/cgi-bin/nph-zms|g'

#
# Required to find the 'mysql' client executable, and may also use 'sudo' if
# installed.
#
SUBST_CLASSES+=			script-path
SUBST_MESSAGE.script-path=	Adjusting paths in scripts.
SUBST_STAGE.script-path=	pre-configure
SUBST_FILES.script-path=	${ZM_REPLACE_PERL}
SUBST_SED.script-path=		-e "s|^\\([\$$]ENV{PATH} *= *'\\).*';\$$|\\1${PREFIX}/bin:/bin:/usr/bin';|g"

SUBST_CLASSES+=		files
SUBST_STAGE.files=	pre-configure
SUBST_FILES.files=	zoneminder.conf
SUBST_SED.files=	-e "s|@ZM_HTTPD_ROOT@|${PREFIX}/${ZM_HTTPD_ROOT}|g"
SUBST_SED.files+=	-e "s|@ZM_HTTPD_CGIBIN@|${PREFIX}/${ZM_HTTPD_CGIBIN}|g"
SUBST_MESSAGE.files=	Fixing ZoneMinder configuration file for Apache.

PLIST_VARS+=		rcd

.if ${INIT_SYSTEM} == "rc.d"
PLIST.rcd=		yes
.endif
PRINT_PLIST_AWK+=	{ gsub(/^.+\/examples\/rc.d/, "$${PLIST.rcd}&"); }

.if ${OPSYS} == "NetBSD" && exists(/usr/include/execinfo.h)
LIBS+=		-lexecinfo
.endif

# Avoid conflict with C++20 <version> - intertwined with patch-CMakeLists.txt
post-extract:
	${CP} ${FILESDIR}/zoneminder.conf ${WRKSRC}/zoneminder.conf
	${MV} ${WRKSRC}/version ${WRKSRC}/version.txt

# Omit patchfiles from PLIST if present.  The pre-configure step below
# should prevent this from being necessary.
PRINT_PLIST_AWK+=	/.orig$$/ { next; }

# After patching remove any .orig files because (for patched .pm files) they
# end up going through the installation process.
pre-configure:
	${FIND} ${WRKSRC} -name "*.pm*.orig" -type f | ${XARGS} ${RM} -f

#
# Arrange for module.mk to perform its magic here on top of the non-Perl
# build tasks.
#
# Set ZM_PERL_MM_PARMS in order to inhibit NO_PACKLIST
#
PERL5_REQD+=		5.6.0
#PERL5_CONFIGURE=	no
#PERL5_CONFIGURE_DIRS=	${WRKSRC}/scripts/ZoneMinder
#PERL5_CONFIGURE_DIRS+=	${WRKSRC}/onvif/proxy
#PERL5_CONFIGURE_DIRS+=	${WRKSRC}/onvif/modules
#PERL5_PACKLIST=	auto/ZoneMinder/.packlist
#PERL5_PACKLIST+=	auto/ONVIF/.packlist
#CMAKE_ARGS+=		-DZM_PERL_MM_PARMS="INSTALLDIRS=vendor"
#.include "../../lang/perl5/module.mk"

#post-configure: perl5-configure

EGDIR=			share/examples/${PKGBASE}
DOCDIR=			share/doc/${PKGBASE}
INSTALLATION_DIRS+=	${EGDIR} ${EGDIR}/config ${EGDIR}/apache
CONF_FILES+=		${PREFIX}/${EGDIR}/config/zm.conf ${PKG_SYSCONFDIR}/zm.conf
INSTALLATION_DIRS+=	bin share/examples/rc.d share/zoneminder/db
INSTALLATION_DIRS+=	${DOCDIR}
post-install:
	${INSTALL_DATA} ${WRKSRC}/zoneminder.conf ${DESTDIR}${PREFIX}/${EGDIR}/apache/zoneminder.conf
	${INSTALL_DATA} ${WRKSRC}/zm.conf ${DESTDIR}${PREFIX}/${EGDIR}/config/zm.conf
.if ${INIT_SYSTEM} == "rc.d"
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/zm ${DESTDIR}${PREFIX}/share/examples/rc.d/zoneminder
.endif
	${INSTALL_DATA} ${WRKSRC}/db/*.sql ${DESTDIR}${PREFIX}/share/zoneminder/db/
	rmdir ${DESTDIR}${PREFIX}/${ZM_HTTPD_ROOT:Q}/events || ${TRUE}
	rmdir ${DESTDIR}${PREFIX}/${ZM_HTTPD_ROOT:Q}/images || ${TRUE}
	${LN} -s ${ZM_CACHE}/temp ${DESTDIR}${PREFIX}/${ZM_HTTPD_ROOT:Q}/temp
	${LN} -s ${ZM_CACHE}/events ${DESTDIR}${PREFIX}/${ZM_HTTPD_ROOT:Q}/events
	${LN} -s ${ZM_CACHE}/images ${DESTDIR}${PREFIX}/${ZM_HTTPD_ROOT:Q}/images
	${INSTALL_DATA} files/README-pkgsrc.md ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

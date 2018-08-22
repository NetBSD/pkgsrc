# $NetBSD: Makefile,v 1.40 2018/08/22 09:46:30 wiz Exp $

PKGNAME=	${DISTNAME:S/ZoneMinder-/zoneminder-/}
DISTNAME=	ZoneMinder-1.28.1
PKGREVISION=	18
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=ZoneMinder/}
GITHUB_PROJECT=	ZoneMinder
GITHUB_TYPE=	tag
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	dsainty@NetBSD.org
HOMEPAGE=	https://www.zoneminder.com/
COMMENT=	Video camera security and surveillance solution
LICENSE=	gnu-gpl-v2

# NetBSD tar: Invalid header, starting valid header search.
EXTRACT_USING=  gtar

DEPENDS+=	netpbm-[0-9]*:../../graphics/netpbm

PHP_VERSIONS_ACCEPTED=	56

PKG_OPTIONS_VAR=	PKG_OPTIONS.zoneminder
PKG_SUPPORTED_OPTIONS=	apache
PKG_SUGGESTED_OPTIONS=	apache

.include "../../mk/bsd.options.mk"

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	aclocal autoconf autoheader automake gmake perl pkg-config

# MIME::Entity is needed from p5-MIME-tools
# LWP::UserAgent is needed from p5-libwww
DEPENDS+=	p5-Archive-Zip-[0-9]*:../../archivers/p5-Archive-Zip
DEPENDS+=	p5-Date-Manip-[0-9]*:../../devel/p5-Date-Manip
DEPENDS+=	p5-Device-SerialPort-[0-9]*:../../comms/p5-Device-SerialPort
DEPENDS+=	p5-DBD-mysql-[0-9]*:../../databases/p5-DBD-mysql
DEPENDS+=	p5-MIME-Lite-[0-9]*:../../mail/p5-MIME-Lite
DEPENDS+=	p5-MIME-tools-[0-9]*:../../mail/p5-MIME-tools
DEPENDS+=	p5-PHP-Serialization-[0-9]*:../../devel/p5-PHP-Serialization
#DEPENDS+=	{perl>=5.7.3,p5-Time-HiRes-[0-9]*}:../../time/p5-Time-HiRes
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

ZM_HTTPD_ROOT=		share/zoneminder/htdocs
PLIST_SUBST+=		ZM_HTTPD_ROOT=${ZM_HTTPD_ROOT:Q}
OWN_DIRS+=		${ZM_HTTPD_ROOT:Q}

ZM_HTTPD_CGIBIN=	libexec/zoneminder/cgi-bin
PLIST_SUBST+=		ZM_HTTPD_CGIBIN=${ZM_HTTPD_CGIBIN:Q}
BUILD_DEFS+=		ZM_HTTPD_CGIBIN
OWN_DIRS+=		${ZM_HTTPD_CGIBIN:Q}

INSTALLATION_DIRS+=	share/zoneminder ${ZM_HTTPD_ROOT}
INSTALLATION_DIRS+=	libexec/zoneminder ${ZM_HTTPD_CGIBIN}

BUILD_DEFS+=		VARBASE
CONFIGURE_ARGS+=	--with-webdir=${PREFIX}/${ZM_HTTPD_ROOT:Q}
CONFIGURE_ARGS+=	--with-cgidir=${PREFIX}/${ZM_HTTPD_CGIBIN:Q}
CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

# PolicyKit doesn't actually seem to be necessary.  This hack disables
# configure's hunt for PolicyKit, but has no other apparent ill effects.
CONFIGURE_ENV+=		POLKIT_CFLAGS=" " POLKIT_LIBS=" "

PTHREAD_AUTO_VARS=	yes
.include "../../mk/pthread.buildlink3.mk"

CONFIGURE_ENV+=		OPT_NETPBM=yes
CONFIGURE_ENV+=		PATH_NETPBM=${PREFIX}/bin/pnmscale

.include "../../multimedia/ffmpeg2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ffmpeg=${BUILDLINK_PREFIX.ffmpeg2}
CONFIGURE_ENV+=		PATH_FFMPEG=${BUILDLINK_PREFIX.ffmpeg2}/bin/ffmpeg2
CONFIGURE_ENV+=		OPT_FFMPEG=yes

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
CONFIGURE_ARGS+=	--with-webgroup=${APACHE_GROUP}

# If we're using Apache we're going to need PHP, and PHP MySQL support.
.include "../../lang/php/phpversion.mk"
DEPENDS+=	${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}-[0-9]*:../../www/ap-php
DEPENDS+=	${PHP_PKG_PREFIX}-mysql-[0-9]*:../../databases/php-mysql
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_mysql-[0-9]*:../../databases/php-pdo_mysql
.endif

# \todo Somehow, this permission setup still fails.
# This directory contains state, so use OWN_DIRS instead of MAKE_DIRS.
ZM_CACHE=	${VARBASE}/cache/zoneminder
OWN_DIRS_PERMS+=	${ZM_CACHE} ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 755
OWN_DIRS_PERMS+=	${ZM_CACHE}/temp ${REAL_ROOT_USER} ${APACHE_GROUP} 775
OWN_DIRS_PERMS+=	${ZM_CACHE}/images ${REAL_ROOT_USER} ${APACHE_GROUP} 775
OWN_DIRS_PERMS+=	${ZM_CACHE}/events ${REAL_ROOT_USER} ${APACHE_GROUP} 775

REPLACE_PERL+=	scripts/zmaudit.pl.in
REPLACE_PERL+=	scripts/zmcamtool.pl.in
REPLACE_PERL+=	scripts/zmcontrol.pl.in
REPLACE_PERL+=	scripts/zmdc.pl.in
REPLACE_PERL+=	scripts/zmfilter.pl.in
REPLACE_PERL+=	scripts/zmpkg.pl.in
REPLACE_PERL+=	scripts/zmtrack.pl.in
REPLACE_PERL+=	scripts/zmtrigger.pl.in
REPLACE_PERL+=	scripts/zmupdate.pl.in
REPLACE_PERL+=	scripts/zmvideo.pl.in
REPLACE_PERL+=	scripts/zmwatch.pl.in
REPLACE_PERL+=	scripts/zmx10.pl.in

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
EXTRA_PERL+=			scripts/zmsystemctl.pl.in

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
SUBST_FILES.script-path=	${REPLACE_PERL} ${EXTRA_PERL}
SUBST_SED.script-path=	-e "s|^\\([\$$]ENV{PATH} *= *'\\).*';\$$|\\1${PREFIX}/bin:/bin:/usr/bin';|g"

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

.if ${OPSYS} == "NetBSD" && exists(/usr/include/execinfo.h)
LIBS+=		-lexecinfo
.endif

post-extract:
	${CP} ${FILESDIR}/zoneminder.conf ${WRKSRC}/zoneminder.conf

pre-configure:
	set -e; cd ${WRKSRC}; \
	aclocal; autoheader; automake -a --foreign -i; autoconf

#
# Arrange for module.mk to perform its magic here on top of the non-Perl
# build tasks.
#
PERL5_REQD+=		5.6.0
PERL5_CONFIGURE=	no
PERL5_CONFIGURE_DIRS=	${WRKSRC}/scripts/ZoneMinder
PERL5_PACKLIST=		auto/ZoneMinder/.packlist
.include "../../lang/perl5/module.mk"

post-configure: perl5-configure

EGDIR=			share/examples/${PKGBASE}
INSTALLATION_DIRS+=	${EGDIR} ${EGDIR}/config ${EGDIR}/apache
CONF_FILES+=		${PREFIX}/${EGDIR}/config/zm.conf ${PKG_SYSCONFDIR}/zm.conf
INSTALLATION_DIRS+=	bin share/examples/rc.d share/zoneminder/db
post-install:
	${INSTALL_DATA} ${WRKSRC}/zoneminder.conf ${DESTDIR}${PREFIX}/${EGDIR}/apache/zoneminder.conf
	${INSTALL_DATA} ${WRKSRC}/zm.conf ${DESTDIR}${PREFIX}/${EGDIR}/config/zm.conf
.if ${INIT_SYSTEM} == "rc.d"
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/zm ${DESTDIR}${PREFIX}/share/examples/rc.d/zoneminder
.endif
	${INSTALL_DATA} ${WRKSRC}/db/*.sql ${DESTDIR}${PREFIX}/share/zoneminder/db/
	rmdir ${DESTDIR}${PREFIX}/${ZM_HTTPD_ROOT:Q}/events || true
	rmdir ${DESTDIR}${PREFIX}/${ZM_HTTPD_ROOT:Q}/images || true
	${LN} -s ${ZM_CACHE}/temp ${DESTDIR}${PREFIX}/${ZM_HTTPD_ROOT:Q}/temp
	${LN} -s ${ZM_CACHE}/events ${DESTDIR}${PREFIX}/${ZM_HTTPD_ROOT:Q}/events
	${LN} -s ${ZM_CACHE}/images ${DESTDIR}${PREFIX}/${ZM_HTTPD_ROOT:Q}/images


.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

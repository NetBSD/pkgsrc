# $NetBSD: Makefile,v 1.26 2020/06/02 08:23:22 adam Exp $
#
# NOTE: when updating this package, there are two places that sound
#       tarballs need to be checked; look in ${WRKSRC}/sounds/Makefile
#       to find out the current sound file versions

DISTNAME=	asterisk-15.4.1
PKGREVISION=	21
CATEGORIES=	comms net audio
MASTER_SITES=	http://downloads.asterisk.org/pub/telephony/asterisk/
MASTER_SITES+=	http://downloads.asterisk.org/pub/telephony/asterisk/old-releases/
MASTER_SITES+=	http://downloads.asterisk.org/pub/telephony/sounds/releases/
DIST_SUBDIR=	${PKGNAME_NOREV}
DISTFILES=	${DEFAULT_DISTFILES}

COMMENT=	The Asterisk Software PBX
LICENSE=	gnu-gpl-v2

EXTRACT_ONLY=	${DISTNAME}.tar.gz
OWNER=		jnemeth@NetBSD.org
HOMEPAGE=	https://www.asterisk.org/

MAKE_JOBS_SAFE=	NO

# known to have issues on i386, block the package until the bug is fixed
BROKEN_ON_PLATFORM=	NetBSD-*-i386

CONFLICTS+=	asterisk-sounds-extra-[0-9]*

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=		bison gmake perl:run pkg-config tar bash:run
USE_LANGUAGES=		c c++
REPLACE_BASH+=		contrib/scripts/astversion
REPLACE_BASH+=		contrib/scripts/ast_coredumper
REPLACE_BASH+=		contrib/scripts/ast_logescalator
REPLACE_BASH+=		contrib/scripts/ast_loggrabber
REPLACE_PERL+=		agi/DialAnMp3.agi agi/agi-test.agi
REPLACE_PERL+=		agi/fastagi-test agi/jukebox.agi agi/numeralize
REPLACE_PERL+=		contrib/scripts/vmail.cgi

CHECK_INTERPRETER_SKIP+=	libdata/asterisk/scripts/refcounter.py

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--datarootdir=${PREFIX}/libdata
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--without-gtk2
# XXX remove when lang/lua gets builtin.mk
CONFIGURE_ARGS+=	--without-lua

.if (${OPSYS} == "NetBSD" && \
    (empty(OS_VERSION:M6.99.[4-9]?) && empty(OS_VERSION:M[7-9].*)))
CONFIGURE_ARGS+=	--without-srtp
.else
CONFIGURE_ARGS+=	--with-srtp
PLIST.srtp=		YES
.include "../../comms/srtp/buildlink3.mk"
.endif

INSTALL_TARGET=		install samples
INSTALLATION_DIRS+=	lib/pkgconfig share/doc/${PKGBASE}
INSTALLATION_DIRS+=	share/examples/asterisk share/examples/rc.d
INSTALLATION_DIRS+=	${ASTDATADIR}/sounds/en ${ASTDATADIR}/moh

BUILD_DEFS+=		VARBASE

ASTERISK_USER?=			asterisk
ASTERISK_GROUP?=		asterisk
PKG_GROUPS=			${ASTERISK_GROUP}
PKG_USERS=			${ASTERISK_USER}:${ASTERISK_GROUP}
PKG_GECOS.${ASTERISK_USER}=	Asterisk PBX
PKG_GROUPS_VARS=		ASTERISK_GROUP
PKG_USERS_VARS=			ASTERISK_USER
FILES_SUBST+=			ASTERISK_USER=${ASTERISK_USER}
FILES_SUBST+=			ASTERISK_GROUP=${ASTERISK_GROUP}
MESSAGE_SUBST+=			ASTERISK_USER=${ASTERISK_USER}
MESSAGE_SUBST+=			ASTERISK_GROUP=${ASTERISK_GROUP}

# Various path settings for Asterisk
PKG_SYSCONFSUBDIR=	asterisk
PKG_SYSCONFDIR_PERMS=	${ASTERISK_USER} ${ASTERISK_GROUP} 0755
ASTETCDIR=		${PKG_SYSCONFDIR}
ASTEXAMPLEDIR=		${PREFIX}/share/examples/asterisk
ASTDBDIR=		${VARBASE}/db/asterisk
ASTSPOOLDIR=		${VARBASE}/spool/asterisk
ASTLOGDIR=		${VARBASE}/log/asterisk
MESSAGE_SUBST+=		ASTDBDIR=${ASTDBDIR}
MESSAGE_SUBST+=		ASTSPOOLDIR=${ASTSPOOLDIR}
MESSAGE_SUBST+=		ASTLOGDIR=${ASTLOGDIR}
ASTVARRUNDIR=		${VARBASE}/run/asterisk
FILES_SUBST+=		ASTVARRUNDIR=${ASTVARRUNDIR}
ASTDATADIR=		${PREFIX}/libdata/asterisk
MAKE_FLAGS+=		ASTLIBDIR=${PREFIX}/lib/asterisk
MAKE_FLAGS+=		ASTVARLIBDIR=${ASTDATADIR}
MAKE_FLAGS+=		ASTKEYDIR=${ASTDATADIR}
MAKE_FLAGS+=		ASTDATADIR=${ASTDATADIR}
MAKE_FLAGS+=		ASTSPOOLDIR=${ASTSPOOLDIR}
MAKE_FLAGS+=		ASTLOGDIR=${ASTLOGDIR}
MAKE_FLAGS+=		ASTHEADERDIR=${PREFIX}/include/asterisk
MAKE_FLAGS+=		ASTCONFPATH=${ASTETCDIR}/asterisk.conf
MAKE_FLAGS+=		ASTBINDIR=${PREFIX}/bin
MAKE_FLAGS+=		ASTSBINDIR=${PREFIX}/sbin
MAKE_FLAGS+=		ASTVARRUNDIR=${ASTVARRUNDIR}
MAKE_FLAGS+=		ASTMANDIR=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=		ASTETCDIR=${ASTETCDIR}
MAKE_FLAGS+=		ASTDBDIR=${ASTDBDIR}
MAKE_FLAGS+=		AGI_DIR=${PREFIX}/libexec/agi-bin
MAKE_FLAGS+=		ASTEXAMPLEDIR=${ASTEXAMPLEDIR}
MAKE_FLAGS+=		WRKSRC=${WRKSRC}
MAKE_FLAGS+=		LDOPTS=${LDFLAGS:M*:Q}
MAKE_FLAGS+=		HTTP_DOCSDIR=${PREFIX}/share/httpd/htdocs
MAKE_FLAGS+=		HTTP_CGIDIR=${PREFIX}/libexec/cgi-bin
MAKE_FLAGS+=		OPTIMIZE=-O3

.if !empty(MACHINE_PLATFORM:MSunOS-*-i386)
BUILDLINK_TRANSFORM+=	rm:-march=i386
.endif

PLIST_VARS+=	kqueue
.if exists(/usr/include/sys/event.h)
PLIST.kqueue=	yes
.endif

PLIST_VARS+=	mgcp
# NOSIGPIPE is a temp variable, since PLIST.mgcp MUST remain undefined
# if the grep fails
.for dir in ${COMPILER_INCLUDE_DIRS}
.  if (exists(${dir}/sys/socket.h))
NOSIGPIPE!=	${GREP} SO_NOSIGPIPE ${dir}/sys/socket.h || echo ""
.    if ${NOSIGPIPE} != ""
PLIST.mgcp=	yes
.    endif
.  endif
.endfor

.if ${OPSYS} == "SunOS"
PLIST.mgcp=	yes
.endif

PLIST_VARS+=	unbound
.if exists(/usr/include/unbound.h)
PLIST.unbound=	yes
.endif

.include "options.mk"

# check sounds/Makefile for current version when upgrading package
DISTFILES+=	asterisk-extra-sounds-en-gsm-1.5.2.tar.gz

# pjproject
PJPROJ_VERSION=	2.7.2
SITES.pjproject-${PJPROJ_VERSION}.tar.bz2= \
	-https://raw.githubusercontent.com/asterisk/third-party/master/pjproject/${PJPROJ_VERSION}/pjproject-${PJPROJ_VERSION}.tar.bz2
SITES.pjproject-${PJPROJ_VERSION}.md5= \
	-https://raw.githubusercontent.com/asterisk/third-party/master/pjproject/${PJPROJ_VERSION}/MD5SUM.TXT
DISTFILES+=	pjproject-${PJPROJ_VERSION}.tar.bz2 pjproject-${PJPROJ_VERSION}.md5
ALL_ENV+=	EXTERNALS_CACHE_DIR=${DISTDIR}/${DIST_SUBDIR}

# Override default paths in config files
SUBST_CLASSES+=		configs
SUBST_STAGE.configs=	pre-configure
SUBST_FILES.configs=	configs/samples/cli_aliases.conf.sample
SUBST_FILES.configs+=	configs/samples/festival.conf.sample
SUBST_FILES.configs+=	configs/samples/http.conf.sample
SUBST_FILES.configs+=	configs/samples/iax.conf.sample
SUBST_FILES.configs+=	configs/samples/musiconhold.conf.sample
SUBST_FILES.configs+=	configs/samples/osp.conf.sample
SUBST_FILES.configs+=	configs/samples/phoneprov.conf.sample
SUBST_FILES.configs+=	configs/samples/res_config_sqlite.conf.sample
SUBST_FILES.configs+=	configs/samples/sla.conf.sample
SUBST_SED.configs+=	-e 's|doc/|${PREFIX}/share/doc/${PKGBASE}/|'
SUBST_SED.configs+=	-e 's|/etc/asterisk|${ASTETCDIR}|'
SUBST_SED.configs+=	-e 's|/var/lib/asterisk|${ASTVARLIBDIR}|'
SUBST_SED.configs+=	-e "s|/usr/local/man|${ASTMANDIR}|"
SUBST_SED.configs+=	-e "s|/usr/local|${PREFIX}|"
SUBST_SED.configs+=	-e "s|/var|${VARBASE}|"

# XXX gross hack, remove when item is fixed
SUBST_CLASSES.NetBSD+=	autoconfig
SUBST_STAGE.autoconfig=	post-configure
SUBST_FILES.autoconfig=	include/asterisk/autoconfig.h
SUBST_SED.autoconfig=	-e "s|^\#define HAVE_GCC_ATOMICS 1|\#undef HAVE_GCC_ATOMICS|"
SUBST_SED.autoconfig+=	-e "s|^\#define HAVE_GETHOSTBYNAME_R_6 1|\#undef HAVE_GETHOSTBYNAME_R_6|"

# XXX gross hack, IP_PKTINFO in NetBSD isn't compatible with anything else
SUBST_CLASSES.NetBSD+=	pktinfo
SUBST_STAGE.pktinfo=	post-configure
SUBST_FILES.pktinfo=	include/asterisk/autoconfig.h
SUBST_SED.pktinfo=	-e "s|^\#define HAVE_PKTINFO 1|\#undef HAVE_PKTINFO|"

# XXX gross hack, gethostbyname_r on NETBSD is for internal use only
SUBST_CLASSES.NetBSD+=		gethostbyname_r
SUBST_STAGE.gethostbyname_r=	post-configure
SUBST_FILES.gethostbyname_r=	include/asterisk/autoconfig.h
SUBST_SED.gethostbyname_r=	-e "s|^\#define HAVE_GETHOSTBYNAME_R_5 1|\#undef HAVE_GETHOSTBYNAME_R_5|"
SUBST_SED.gethostbyname_r+=	-e "s|^\#define HAVE_GETHOSTBYNAME_R_6 1|\#undef HAVE_GETHOSTBYNAME_R_6|"

RCD_SCRIPTS=		asterisk
OWN_DIRS_PERMS+=	${ASTDBDIR} ${ASTERISK_USER} ${ASTERISK_GROUP} 0755
OWN_DIRS_PERMS+=	${ASTSPOOLDIR} ${ASTERISK_USER} ${ASTERISK_GROUP} 0755
OWN_DIRS_PERMS+=	${ASTSPOOLDIR}/dictate ${ASTERISK_USER} ${ASTERISK_GROUP} 0755
OWN_DIRS_PERMS+=	${ASTSPOOLDIR}/meetme ${ASTERISK_USER} ${ASTERISK_GROUP} 0755
OWN_DIRS_PERMS+=	${ASTSPOOLDIR}/monitor ${ASTERISK_USER} ${ASTERISK_GROUP} 0755
OWN_DIRS_PERMS+=	${ASTSPOOLDIR}/outgoing ${ASTERISK_USER} ${ASTERISK_GROUP} 0755
OWN_DIRS_PERMS+=	${ASTSPOOLDIR}/system ${ASTERISK_USER} ${ASTERISK_GROUP} 0755
OWN_DIRS_PERMS+=	${ASTSPOOLDIR}/tmp ${ASTERISK_USER} ${ASTERISK_GROUP} 0755
OWN_DIRS_PERMS+=	${ASTSPOOLDIR}/voicemail ${ASTERISK_USER} ${ASTERISK_GROUP} 0755
OWN_DIRS_PERMS+=	${ASTSPOOLDIR}/voicemail/default ${ASTERISK_USER} ${ASTERISK_GROUP} 0755
OWN_DIRS_PERMS+=	${ASTSPOOLDIR}/voicemail/default/1234 ${ASTERISK_USER} ${ASTERISK_GROUP} 0755
OWN_DIRS_PERMS+=	${ASTSPOOLDIR}/voicemail/default/1234/INBOX ${ASTERISK_USER} ${ASTERISK_GROUP} 0755
OWN_DIRS_PERMS+=	${ASTSPOOLDIR}/voicemail/default/1234/en ${ASTERISK_USER} ${ASTERISK_GROUP} 0755
SPECIAL_PERMS+=		${ASTSPOOLDIR}/voicemail/default/1234/en/busy.gsm ${ASTERISK_USER} ${ASTERISK_GROUP} 0644
SPECIAL_PERMS+=		${ASTSPOOLDIR}/voicemail/default/1234/en/unavail.gsm ${ASTERISK_USER} ${ASTERISK_GROUP} 0644
OWN_DIRS_PERMS+=	${ASTSPOOLDIR}/voicemail/default/INBOX ${ASTERISK_USER} ${ASTERISK_GROUP} 0755
OWN_DIRS_PERMS+=	${ASTSPOOLDIR}/voicemail/default/en ${ASTERISK_USER} ${ASTERISK_GROUP} 0755
OWN_DIRS_PERMS+=	${ASTLOGDIR} ${ASTERISK_USER} ${ASTERISK_GROUP} 0755
OWN_DIRS_PERMS+=	${ASTLOGDIR}/cdr-csv ${ASTERISK_USER} ${ASTERISK_GROUP} 0755
OWN_DIRS_PERMS+=	${ASTLOGDIR}/cdr-custom ${ASTERISK_USER} ${ASTERISK_GROUP} 0755

CONF_FILES_PERMS=	# empty
.for f in asterisk.conf extensions.conf
CONF_FILES_PERMS+=	${ASTEXAMPLEDIR}/${f:Q} ${PKG_SYSCONFDIR}/${f:Q} ${ASTERISK_USER} ${ASTERISK_GROUP} 0644
.endfor

.if !empty(PKG_OPTIONS:Masterisk-config)
# if we put all the files in $CONF_FILES, the message is _way_ too long.
.  for f in acl.conf adsi.conf agents.conf alarmreceiver.conf alsa.conf	\
	amd.conf app_mysql.conf app_skel.conf ari.conf			\
	ast_debug_tools.conf asterisk.adsi calendar.conf ccss.conf	\
	cdr.conf cdr_adaptive_odbc.conf cdr_custom.conf			\
	cdr_manager.conf cdr_mysql.conf cdr_odbc.conf cdr_pgsql.conf	\
	cdr_sqlite3_custom.conf cdr_syslog.conf cdr_tds.conf cel.conf	\
	cel_custom.conf cel_odbc.conf cel_pgsql.conf			\
	cel_sqlite3_custom.conf cel_tds.conf chan_dahdi.conf		\
	chan_mobile.conf cli.conf cli_aliases.conf cli_permissions.conf	\
	codecs.conf confbridge.conf console.conf dbsep.conf dnsmgr.conf	\
	dsp.conf dundi.conf enum.conf extconfig.conf extensions.ael	\
	extensions.conf extensions.lua	extensions_minivm.conf		\
	features.conf festival.conf followme.conf func_odbc.conf	\
	hep.conf http.conf iax.conf iaxprov.conf indications.conf	\
	logger.conf manager.conf meetme.conf mgcp.conf minivm.conf	\
	misdn.conf modules.conf	motif.conf musiconhold.conf muted.conf	\
	ooh323.conf osp.conf oss.conf phone.conf phoneprov.conf		\
	pjproject.conf pjsip.conf pjsip_notify.conf pjsip_wizard.conf	\
	queuerules.conf queues.conf res_config_mysql.conf		\
	res_config_sqlite.conf res_config_sqlite3.conf			\
	res_corosync.conf res_curl.conf	 res_fax.conf res_ldap.conf	\
	res_odbc.conf res_parking.conf res_pgsql.conf res_pktccops.conf	\
	res_snmp.conf res_stun_monitor.conf resolver_unbound.conf	\
	rtp.conf say.conf sip.conf sip_notify.conf skinny.conf sla.conf	\
	smdi.conf sorcery.conf ss7.timers stasis.conf statsd.conf	\
	telcordia-1.adsi udptl.conf unistim.conf users.conf		\
	voicemail.conf vpb.conf xmpp.conf
CONF_FILES_PERMS+=		${ASTEXAMPLEDIR}/${f:Q} ${PKG_SYSCONFDIR}/${f:Q} ${ASTERISK_USER} ${ASTERISK_GROUP} 0644
.  endfor
.endif

PTHREAD_OPTS+=	require native

.if (${OPSYS} == "Darwin" && exists(/usr/include/sys/poll.h))
post-patch:
	${ECHO} "#include <sys/poll.h>" > ${WRKSRC}/include/asterisk/poll-compat.h
.endif

post-install:
# check sounds directory for current versions when upgrading package
	${TAR} xzf ${WRKSRC}/sounds/asterisk-core-sounds-en-gsm-1.6.1.tar.gz -C ${DESTDIR}${ASTDATADIR}/sounds/en
	${TAR} xzf ${WRKSRC}/sounds/asterisk-moh-opsound-wav-2.03.tar.gz -C ${DESTDIR}${ASTDATADIR}/moh
	${TAR} xzf ${DISTDIR}/${DIST_SUBDIR}/asterisk-extra-sounds-en-gsm-1.5.2.tar.gz -C ${DESTDIR}${ASTDATADIR}/sounds/en
	${INSTALL_DATA} ${WRKSRC}/BUGS ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/CREDITS ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/README-SERIOUSLY.bestpractices.md ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/UPGRADE-1.2.txt ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/UPGRADE-1.4.txt ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/UPGRADE-1.6.txt ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/UPGRADE-1.8.txt ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/UPGRADE-10.txt ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/UPGRADE-11.txt ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/UPGRADE-12.txt ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/UPGRADE-13.txt ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/UPGRADE-14.txt ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/UPGRADE.txt ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/Zaptel-to-DAHDI.txt ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/doc/IAX2-security.pdf ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/doc/IAX2-security.txt ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/doc/README.txt ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.if ${OPSYS} != "Darwin" && ${PKGSRC_COMPILER} == "clang"
.include "../../lang/libBlocksRuntime/buildlink3.mk"
LDFLAGS+= -L${PREFIX}/lib
.endif

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

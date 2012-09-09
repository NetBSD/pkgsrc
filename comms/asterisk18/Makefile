# $NetBSD: Makefile,v 1.45 2012/09/09 06:04:01 jnemeth Exp $
#
# NOTE: when updating this package, there are two places that sound
#       tarballs need to be checked

DISTNAME=	asterisk-1.8.15.1
DIST_SUBDIR=	${PKGNAME_NOREV}
DISTFILES=	${DEFAULT_DISTFILES}
EXTRACT_ONLY=	${DISTNAME}.tar.gz
CATEGORIES=	comms net audio
MASTER_SITES=	http://downloads.asterisk.org/pub/telephony/asterisk/ \
		http://downloads.asterisk.org/pub/telephony/asterisk/old-releases/ \
		http://downloads.asterisk.org/pub/telephony/sounds/releases/

OWNER=		jnemeth@NetBSD.org
HOMEPAGE=	http://www.asterisk.org/
COMMENT=	The Asterisk Software PBX
LICENSE=	gnu-gpl-v2

CONFLICTS+=	asterisk-sounds-extra-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=		bison gmake perl:run pkg-config tar
USE_LANGUAGES=		c c++
REPLACE_PERL+=		agi/DialAnMp3.agi agi/agi-test.agi
REPLACE_PERL+=		agi/fastagi-test agi/jukebox.agi agi/numeralize
REPLACE_PERL+=		contrib/scripts/vmail.cgi

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--datarootdir=${PREFIX}/libdata
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--without-gtk2
# XXX remove when lang/lua gets builtin.mk
CONFIGURE_ARGS+=	--without-lua
CONFIGURE_ARGS+=	--with-oss=yes

INSTALL_TARGET=		install samples
INSTALLATION_DIRS+=	lib/pkgconfig share/doc/${PKGBASE}
INSTALLATION_DIRS+=	share/examples/asterisk share/examples/rc.d
INSTALLATION_DIRS+=	${ASTDATADIR}/sounds/en ${ASTDATADIR}/moh

BUILD_DEFS+=		VARBASE

ASTERISK_USER?=		asterisk
ASTERISK_GROUP?=	asterisk
PKG_GROUPS=		${ASTERISK_GROUP}
PKG_USERS=		${ASTERISK_USER}:${ASTERISK_GROUP}
PKG_GECOS.${ASTERISK_USER}=	Asterisk PBX
PKG_GROUPS_VARS=	ASTERISK_GROUP
PKG_USERS_VARS=		ASTERISK_USER
FILES_SUBST+=		ASTERISK_USER=${ASTERISK_USER}
FILES_SUBST+=		ASTERISK_GROUP=${ASTERISK_GROUP}
MESSAGE_SUBST+=		ASTERISK_USER=${ASTERISK_USER}
MESSAGE_SUBST+=		ASTERISK_GROUP=${ASTERISK_GROUP}

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
NOSIGPIPE!=	${GREP} SO_NOSIGPIPE /usr/include/sys/socket.h || echo ""
.if ${NOSIGPIPE} != ""
PLIST.mgcp= yes
.endif

.include "options.mk"

# check sounds/Makefile for current version when upgrading package
DISTFILES+=	asterisk-extra-sounds-en-gsm-1.4.11.tar.gz

# Override default paths in config files
SUBST_CLASSES+=		configs
SUBST_STAGE.configs=	pre-configure
SUBST_FILES.configs=	configs/festival.conf.sample
SUBST_FILES.configs+=	configs/http.conf.sample
SUBST_FILES.configs+=	configs/musiconhold.conf.sample
SUBST_FILES.configs+=	configs/osp.conf.sample
SUBST_FILES.configs+=	configs/phoneprov.conf.sample
SUBST_FILES.configs+=	configs/res_config_sqlite.conf.sample
SUBST_SED.configs+=	-e 's|/var/lib/asterisk|${ASTVARLIBDIR}|'
SUBST_SED.configs+=	-e "s|/usr/local/man|${ASTMANDIR}|"
SUBST_SED.configs+=	-e "s|/usr/local|${PREFIX}|"
SUBST_SED.configs+=	-e "s|/var|${VARBASE}|"

# XXX gross hack, remove when atomics properly implemented
.if (${OPSYS} == "NetBSD")
SUBST_CLASSES+=		atomics
SUBST_STAGE.atomics=	post-configure
SUBST_FILES.atomics=	include/asterisk/autoconfig.h
SUBST_SED.atomics=	-e "s|^\#define HAVE_GCC_ATOMICS 1|\#undef HAVE_GCC_ATOMICS|"
.endif

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

# if we put all the files in $CONF_FILES, the message is _way_ too long.
.for f in adsi.conf agents.conf ais.conf alarmreceiver.conf alsa.conf	\
	amd.conf app_mysql.conf asterisk.adsi calendar.conf ccss.conf	\
	cdr.conf cdr_adaptive_odbc.conf cdr_custom.conf			\
	cdr_manager.conf cdr_mysql.conf	cdr_odbc.conf cdr_pgsql.conf	\
	cdr_sqlite3_custom.conf cdr_tds.conf cel.conf cel_custom.conf	\
	cel_odbc.conf cel_pgsql.conf cel_sqlite3_custom.conf		\
	cel_tds.conf chan_dahdi.conf chan_mobile.conf chan_ooh323.conf	\
	cli.conf cli_aliases.conf cli_permissions.conf codecs.conf	\
	console.conf dbsep.conf dnsmgr.conf dsp.conf dundi.conf		\
	enum.conf extconfig.conf extensions.ael extensions.conf		\
	extensions.lua extensions_minivm.conf features.conf		\
	festival.conf followme.conf func_odbc.conf gtalk.conf h323.conf	\
	http.conf iax.conf iaxprov.conf indications.conf jabber.conf	\
	jingle.conf logger.conf manager.conf meetme.conf mgcp.conf	\
	minivm.conf misdn.conf modules.conf musiconhold.conf muted.conf	\
	osp.conf oss.conf phone.conf phoneprov.conf queuerules.conf	\
	queues.conf res_config_mysql.conf res_config_sqlite.conf	\
	res_curl.conf res_fax.conf res_ldap.conf res_odbc.conf		\
	res_pgsql.conf res_pktccops.conf res_snmp.conf			\
	res_stun_monitor.conf rtp.conf say.conf sip.conf udptl.conf	\
	unistim.conf users.conf voicemail.conf vpb.conf
CONF_FILES_PERMS+=		${ASTEXAMPLEDIR}/${f:Q} ${PKG_SYSCONFDIR}/${f:Q} ${ASTERISK_USER} ${ASTERISK_GROUP} 0644
.endfor

PTHREAD_OPTS+=	require native

.if (${OPSYS} == "Darwin" && exists(/usr/include/sys/poll.h))
post-patch:
	${ECHO} "#include <sys/poll.h>" > ${WRKSRC}/include/asterisk/poll-compat.h
.endif

post-install:
# check sounds directory for current versions when upgrading package
	${TAR} xzf ${WRKSRC}/sounds/asterisk-core-sounds-en-gsm-1.4.22.tar.gz -C ${DESTDIR}${ASTDATADIR}/sounds/en
	${TAR} xzf ${WRKSRC}/sounds/asterisk-moh-opsound-wav-2.03.tar.gz -C ${DESTDIR}${ASTDATADIR}/moh
	${TAR} xzf ${DISTDIR}/${DIST_SUBDIR}/asterisk-extra-sounds-en-gsm-1.4.11.tar.gz -C ${DESTDIR}${ASTDATADIR}/sounds/en
	${INSTALL_DATA} ${WRKSRC}/BUGS ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/CREDITS ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/README-SERIOUSLY.bestpractices.txt ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/UPGRADE-1.2.txt ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/UPGRADE-1.4.txt ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/UPGRADE-1.6.txt ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/UPGRADE.txt ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/Zaptel-to-DAHDI.txt ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/doc/IAX2-security.pdf ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/doc/IAX2-security.txt ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/doc/README.txt ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/doc/api-1.6.2-changes.txt ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	cp -r ${WRKSRC}/doc/Asterisk-Admin-Guide ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/Asterisk-Admin-Guide

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

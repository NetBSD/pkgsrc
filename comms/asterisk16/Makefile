# $NetBSD: Makefile,v 1.1.1.1.2.1 2009/09/13 14:18:23 tron Exp $
#

DISTNAME=	asterisk-1.6.0.15
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_ONLY=	${DISTNAME}.tar.gz
CATEGORIES=	comms net audio
MASTER_SITES=	http://downloads.asterisk.org/pub/telephony/asterisk/ \
		http://downloads.asterisk.org/pub/telephony/asterisk/old-releases/

OWNER=		jnemeth@NetBSD.org
HOMEPAGE=	http://www.asterisk.org/
COMMENT=	The Asterisk Software PBX
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=		bash bison gmake perl:run pkg-config
USE_LANGUAGES=		c c++
REPLACE_BASH=		build_tools/mkpkgconfig
REPLACE_PERL+=		agi/DialAnMp3.agi agi/agi-test.agi
REPLACE_PERL+=		agi/fastagi-test agi/jukebox.agi agi/numeralize

PKGCONFIG_OVERRIDE+=	menuselect/mxml/mxml.pc.in

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--datarootdir=${PREFIX}/libdata
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--without-gtk2

INSTALL_TARGET=		install samples
INSTALLATION_DIRS=	lib/pkgconfig
INSTALLATION_DIRS+=	share/examples/asterisk share/examples/rc.d

BUILD_DEFS+=		VARBASE

# Running as non-root will come later
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
MAKE_FLAGS+=		ASTLIBDIR=${PREFIX}/lib/asterisk
MAKE_FLAGS+=		ASTVARLIBDIR=${PREFIX}/libdata/asterisk
MAKE_FLAGS+=		ASTKEYDIR=${PREFIX}/libdata/asterisk
MAKE_FLAGS+=		ASTDATADIR=${PREFIX}/libdata/asterisk
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
MAKE_FLAGS+=		GLOBAL_MAKEOPTS=${WRKSRC}/pkgsrc.makeopts
MAKE_FLAGS+=		LDOPTS=${LDFLAGS:M*:Q}

.include "options.mk"

# Override default paths in config files
SUBST_CLASSES+=		configs
SUBST_STAGE.configs=	pre-configure
SUBST_FILES.configs=	configs/festival.conf.sample
SUBST_FILES.configs+=	configs/http.conf.sample
SUBST_FILES.configs+=	configs/musiconhold.conf.sample
SUBST_FILES.configs+=	configs/osp.conf.sample
SUBST_FILES.configs+=	configs/phoneprov.conf.sample
SUBST_FILES.configs+=	configs/res_config_sqlite.conf
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
.for f in adsi.conf adtranvofr.conf agents.conf alarmreceiver.conf	\
	alsa.conf amd.conf asterisk.adsi cdr.conf 			\
	cdr_adaptive_odbc.conf cdr_custom.conf cdr_manager.conf		\
	cdr_odbc.conf cdr_pgsql.conf cdr_sqlite3_custom.conf		\
	cdr_tds.conf chan_dahdi.conf cli.conf codecs.conf console.conf	\
	dnsmgr.conf dundi.conf enum.conf extensions.ael extconfig.conf	\
	extensions.conf	extensions.lua extensions_minivm.conf		\
	features.conf festival.conf followme.conf func_odbc.conf	\
	gtalk.conf h323.conf http.conf iax.conf iaxprov.conf		\
	indications.conf jabber.conf jingle.conf logger.conf		\
	manager.conf meetme.conf mgcp.conf minivm.conf misdn.conf	\
	modules.conf musiconhold.conf muted.conf osp.conf oss.conf	\
	phone.conf phoneprov.conf queuerules.conf queues.conf		\
	res_ldap.conf res_odbc.conf res_pgsql.conf res_snmp.conf	\
	rpt.conf rtp.conf say.conf sip.conf sip_notify.conf skinny.conf	\
	sla.conf smdi.conf telcordia-1.adsi udptl.conf unistim.conf	\
	usbradio.conf users.conf voicemail.conf vpb.conf
CONF_FILES_PERMS+=		${ASTEXAMPLEDIR}/${f:Q} ${PKG_SYSCONFDIR}/${f:Q} ${ASTERISK_USER} ${ASTERISK_GROUP} 0644
.endfor

PTHREAD_OPTS+=	require native

.if (${OPSYS} == "Darwin" && exists(/usr/include/sys/poll.h))
post-patch:
	${ECHO} "#include <sys/poll.h>" > ${WRKSRC}/include/asterisk/poll-compat.h
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

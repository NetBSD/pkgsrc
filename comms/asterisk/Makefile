# $NetBSD: Makefile,v 1.74 2012/10/03 11:24:38 asau Exp $

DISTNAME=	asterisk-1.2.37
PKGREVISION=	3
CATEGORIES=	comms net audio
MASTER_SITES=	http://downloads.asterisk.org/pub/telephony/asterisk/releases/ \
		http://downloads.asterisk.org/pub/telephony/asterisk/old-releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.asterisk.org/
COMMENT=	The Asterisk Software PBX
LICENSE=	gnu-gpl-v2

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=		bash bison gmake perl:run
REPLACE_BASH=		mkpkgconfig
REPLACE_PERL+=		agi/agi-test.agi

INSTALL_TARGET=		install samples
INSTALLATION_DIRS=	lib/pkgconfig

BUILD_DEFS+=		VARBASE

# Running as non-root will come later
#ASTERISK_USER?= 	asterisk
#ASTERISK_GROUP?= 	asterisk
#PKG_GROUPS= 		${ASTERISK_GROUP}
#PKG_USERS= 		${ASTERISK_USER}:${ASTERISK_GROUP}
#PKG_GROUPS_VARS+=	ASTERISK_GROUP
#PKG_USERS_VARS+=	ASTERISK_USER

# Various path settings for Asterisk
PKG_SYSCONFSUBDIR=	asterisk
ASTLIBDIR?=		${PREFIX}/lib/asterisk
ASTVARLIBDIR?=		${PREFIX}/libdata/asterisk
ASTETCDIR?=		${PKG_SYSCONFDIR}
ASTSPOOLDIR?=		${VARBASE}/spool/asterisk
ASTLOGDIR?=		${VARBASE}/log/asterisk
ASTHEADERDIR?=		${PREFIX}/include/asterisk
ASTCONFPATH?=		${ASTETCDIR}/asterisk.conf
ASTBINDIR?=		${PREFIX}/bin
ASTSBINDIR?=		${PREFIX}/sbin
ASTVARRUNDIR?=		${VARBASE}/run
ASTMANDIR?=		${PREFIX}/${PKGMANDIR}
ASTEXAMPLEDIR?=		${PREFIX}/share/examples/asterisk

# Override default paths in Makefile
SUBST_CLASSES+=		asterisk
SUBST_STAGE.asterisk=	pre-configure
SUBST_FILES.asterisk=	Makefile configs/musiconhold.conf.sample
SUBST_SED.asterisk+=	-e 's|/var/lib/asterisk|${ASTVARLIBDIR}|'
SUBST_SED.asterisk+=	-e 's|^ *\(ASTLIBDIR\)=.*|\1 = ${ASTLIBDIR}|'
SUBST_SED.asterisk+=	-e 's|^ *\(ASTVARLIBDIR\)=.*|\1 = ${ASTVARLIBDIR}|'
SUBST_SED.asterisk+=	-e 's|^ *\(ASTETCDIR\)=.*|\1 = ${ASTETCDIR}|'
SUBST_SED.asterisk+=	-e 's|^ *\(ASTSPOOLDIR\)=.*|\1 = ${ASTSPOOLDIR}|'
SUBST_SED.asterisk+=	-e 's|^ *\(ASTLOGDIR\)=.*|\1 = ${ASTLOGDIR}|'
SUBST_SED.asterisk+=	-e 's|^ *\(ASTHEADERDIR\)=.*|\1 = ${ASTHEADERDIR}|'
SUBST_SED.asterisk+=	-e 's|^ *\(ASTCONFPATH\)=.*|\1 = ${ASTCONFPATH:Q}|'
SUBST_SED.asterisk+=	-e 's|^ *\(ASTBINDIR\)=.*|\1 = ${ASTBINDIR}|'
SUBST_SED.asterisk+=	-e 's|^ *\(ASTSBINDIR\)=.*|\1 = ${ASTSBINDIR}|'
SUBST_SED.asterisk+=	-e 's|^ *\(ASTVARRUNDIR\)=.*|\1 = ${ASTVARRUNDIR}|'
SUBST_SED.asterisk+=	-e 's|^ *\(ASTMANDIR\)=.*|\1 = ${ASTMANDIR}|'
SUBST_SED.asterisk+=	-e 's|^ *\(ASTEXAMPLEDIR\)=.*|\1 = ${ASTEXAMPLEDIR}|'

.include "options.mk"

RCD_SCRIPTS=		asterisk
OWN_DIRS+=		${ASTSPOOLDIR} ${ASTLOGDIR} ${ASTVARRUNDIR}
OWN_DIRS+=		${ASTLOGDIR}/cdr-csv
# XXX: should be in ${VARBASE}
OWN_DIRS+=		${ASTVARLIBDIR}/sounds/priv-callerintros

CONF_FILES=		# empty
.for f in asterisk.conf extensions.conf
CONF_FILES+=	${ASTEXAMPLEDIR}/${f:Q} ${ASTETCDIR}/${f:Q}
.endfor

MAKE_ENV+=		VARBASE=${VARBASE}
MAKE_ENV+=		PKGSRC_RPATH=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.curl}/lib
MAKE_FLAGS+=		INSTALL_PREFIX=${PREFIX}

# if we put all the files in $CONF_FILES, the message is _way_ too long.
.for f in adsi.conf adtranvofr.conf agents.conf alarmreceiver.conf	\
	alsa.conf cdr_manager.conf cdr_odbc.conf 			\
	cdr_pgsql.conf cdr_tds.conf enum.conf extconfig.conf 		\
	features.conf festival.conf iax.conf 				\
	iaxprov.conf indications.conf logger.conf manager.conf 		\
	meetme.conf mgcp.conf modem.conf modules.conf musiconhold.conf 	\
	osp.conf oss.conf phone.conf privacy.conf queues.conf		\
	res_odbc.conf rpt.conf rtp.conf sip.conf 			\
	skinny.conf voicemail.conf vpb.conf zapata.conf asterisk.adsi 	\
	telcordia-1.adsi
CONF_FILES+=		${ASTEXAMPLEDIR}/${f:Q} ${ASTETCDIR}/${f:Q}
.endfor

PTHREAD_OPTS+=	require native

.if (${OPSYS} == "Darwin" && exists(/usr/include/sys/poll.h))
post-patch:
	${ECHO} "#include <sys/poll.h>" > ${WRKSRC}/include/asterisk/poll-compat.h
.endif

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

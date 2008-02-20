# $NetBSD: Makefile,v 1.46 2008/02/20 10:14:19 wiz Exp $

DISTNAME=	asterisk-1.2.24
PKGREVISION=	2
CATEGORIES=	comms net audio
MASTER_SITES=	http://ftp.digium.com/pub/asterisk/ \
		http://ftp.digium.com/pub/asterisk/old-releases/

MAINTAINER=	riz@NetBSD.org
HOMEPAGE=	http://www.asterisk.org/
COMMENT=	The Asterisk Software PBX

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=		bison gmake perl:run
REPLACE_PERL+=		agi/agi-test.agi

INSTALL_TARGET=		install samples

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
ASTMANDIR?=		${PREFIX}/man
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
SUBST_SED.asterisk+=	-e 's|^ *\(ASTCONFPATH\)=.*|\1 = ${ASTCONFPATH}|'
SUBST_SED.asterisk+=	-e 's|^ *\(ASTBINDIR\)=.*|\1 = ${ASTBINDIR}|'
SUBST_SED.asterisk+=	-e 's|^ *\(ASTSBINDIR\)=.*|\1 = ${ASTSBINDIR}|'
SUBST_SED.asterisk+=	-e 's|^ *\(ASTVARRUNDIR\)=.*|\1 = ${ASTVARRUNDIR}|'
SUBST_SED.asterisk+=	-e 's|^ *\(ASTMANDIR\)=.*|\1 = ${ASTMANDIR}|'
SUBST_SED.asterisk+=	-e 's|^ *\(ASTEXAMPLEDIR\)=.*|\1 = ${ASTEXAMPLEDIR}|'

.include "options.mk"

RCD_SCRIPTS=		asterisk
OWN_DIRS+=		${ASTSPOOLDIR} ${ASTLOGDIR} ${ASTVARRUNDIR}
OWN_DIRS+=		${ASTLOGDIR}/cdr-csv

CONF_FILES=		# empty
.for f in asterisk.conf extensions.conf
CONF_FILES+=	${ASTEXAMPLEDIR:Q}/${f:Q} ${ASTETCDIR:Q}/${f:Q}
.endfor

MAKE_ENV+=		VARBASE=${VARBASE:Q}
MAKE_FLAGS+=		INSTALL_PREFIX=${PREFIX:Q}

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
CONF_FILES+=		${ASTEXAMPLEDIR:Q}/${f:Q} ${ASTETCDIR:Q}/${f:Q}
.endfor

PTHREAD_OPTS+=	require native

.if (${OPSYS} == "Darwin" && exists(/usr/include/sys/poll.h))
post-patch:
	${ECHO} "#include <sys/poll.h>" > ${WRKSRC:Q}/include/asterisk/poll-compat.h
.endif

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

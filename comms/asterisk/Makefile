# $NetBSD: Makefile,v 1.16 2006/01/24 02:09:38 riz Exp $

DISTNAME=	asterisk-1.2.2
CATEGORIES=	comms net audio
MASTER_SITES=	http://ftp.digium.com/pub/asterisk/ \
		http://ftp.digium.com/pub/asterisk/old-releases

MAINTAINER=	riz@NetBSD.org
HOMEPAGE=	http://www.asterisk.org/
COMMENT=	The Asterisk Software PBX

USE_TOOLS+= 		bison gmake

# MANCOMPRESSED= 		yes

INSTALL_TARGET= 	install samples

# Running as non-root will come later
#ASTERISK_USER?= 	asterisk
#ASTERISK_GROUP?= 	asterisk
#PKG_GROUPS= 		${ASTERISK_GROUP}
#PKG_USERS= 		${ASTERISK_USER}:${ASTERISK_GROUP}::Asterisk\\ user

# Various path settings for Asterisk
PKG_SYSCONFSUBDIR?=	asterisk
ASTLIBDIR?=${PREFIX}/lib/asterisk
ASTVARLIBDIR?=${PREFIX}/libdata/asterisk
ASTETCDIR?=${PKG_SYSCONFDIR}
ASTSPOOLDIR?=${VARBASE}/spool/asterisk
ASTLOGDIR?=${VARBASE}/log/asterisk
ASTHEADERDIR?=${PREFIX}/include/asterisk
ASTCONFPATH?=${ASTETCDIR}/asterisk.conf
ASTBINDIR?=${PREFIX}/bin
ASTSBINDIR?=${PREFIX}/sbin
ASTVARRUNDIR?=${VARBASE}/run
ASTMANDIR?=${PREFIX}/man
ASTEXAMPLEDIR?=${PREFIX}/share/examples/asterisk

# Override default paths in Makefile
SUBST_CLASSES+= 	asterisk
SUBST_STAGE.asterisk= 	pre-configure
SUBST_FILES.asterisk=	Makefile configs/musiconhold.conf.sample
SUBST_SED.asterisk= 	\
	-e "s|/var/lib/asterisk|${ASTVARLIBDIR}|"		\
	-e "s|^ *\(ASTLIBDIR\)=.*|\1 = ${ASTLIBDIR}|"		\
	-e "s|^ *\(ASTVARLIBDIR\)=.*|\1 = ${ASTVARLIBDIR}|"	\
	-e "s|^ *\(ASTETCDIR\)=.*|\1 = ${ASTETCDIR}|"		\
	-e "s|^ *\(ASTSPOOLDIR\)=.*|\1 = ${ASTSPOOLDIR}|"		\
	-e "s|^ *\(ASTLOGDIR\)=.*|\1 = ${ASTLOGDIR}|"		\
	-e "s|^ *\(ASTHEADERDIR\)=.*|\1 = ${ASTHEADERDIR}|"	\
	-e "s|^ *\(ASTCONFPATH\)=.*|\1 = ${ASTCONFPATH}|"		\
	-e "s|^ *\(ASTBINDIR\)=.*|\1 = ${ASTBINDIR}|"		\
	-e "s|^ *\(ASTSBINDIR\)=.*|\1 = ${ASTSBINDIR}|"		\
	-e "s|^ *\(ASTVARRUNDIR\)=.*|\1 = ${ASTVARRUNDIR}|"	\
	-e "s|^ *\(ASTMANDIR\)=.*|\1 = ${ASTMANDIR}|"		\
	-e "s|^ *\(ASTEXAMPLEDIR\)=.*|\1 = ${ASTEXAMPLEDIR}|"

.include "options.mk"

USE_PKGINSTALL= 	yes
RCD_SCRIPTS= 		asterisk
OWN_DIRS+= 		${ASTSPOOLDIR} ${ASTLOGDIR} ${ASTVARRUNDIR}
OWN_DIRS+=		${ASTLOGDIR}/cdr-csv

CONF_FILES=		# empty
.for _file_ in asterisk.conf extensions.conf
CONF_FILES+=	${ASTEXAMPLEDIR}/${_file_} ${ASTETCDIR}/${_file_}
.endfor

MAKE_FLAGS+=   INSTALL_PREFIX=${PREFIX}
 
# if we put all the files in $CONF_FILES, the message is _way_ too long.
.for _file_ in adsi.conf adtranvofr.conf agents.conf alarmreceiver.conf \
	alsa.conf cdr_manager.conf cdr_odbc.conf 			\
	cdr_pgsql.conf cdr_tds.conf enum.conf extconfig.conf 		\
	features.conf festival.conf iax.conf 				\
	iaxprov.conf indications.conf logger.conf manager.conf 		\
	meetme.conf mgcp.conf modem.conf modules.conf musiconhold.conf 	\
	osp.conf oss.conf phone.conf privacy.conf queues.conf		\
	res_config_odbc.conf res_odbc.conf rpt.conf rtp.conf sip.conf 	\
	skinny.conf voicemail.conf vpb.conf zapata.conf asterisk.adsi 	\
	telcordia-1.adsi
CONF_FILES+= 	${ASTEXAMPLEDIR}/${_file_} ${ASTETCDIR}/${_file_}
.endfor

PTHREAD_OPTS+=	require native

.if (${OPSYS} == "Darwin" && exists(/usr/include/sys/poll.h))
post-patch:
	${ECHO} "#include <sys/poll.h>" > ${WRKSRC}/include/asterisk/poll-compat.h
.endif

.include "../../devel/ncurses/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

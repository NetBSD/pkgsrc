# $NetBSD: Makefile,v 1.1.1.1 1999/10/05 12:37:18 wennmach Exp $

DISTNAME=	jitterbug-1.6.2
WRKSRC=		${WRKDIR}/${PKGNAME}/source
CATEGORIES=	misc
MASTER_SITES=	ftp://jitterbug.samba.org/pub/jitterbug/

MAINTAINER=	wennmach@netbsd.org
HOMEPAGE=	http://jitterbug.samba.org/

DEPENDS+=	addnerd:../../sysutils/addnerd
DEPENDS+=	apache-1.3.*:../../www/apache

PLIST_SRC=	${WRKDIR}/PLIST.tmp
REQ_FILE=	${WRKDIR}/REQ
CONFIGDIR=	${WRKDIR}/${PKGNAME}/config
DOCSDIR=	${WRKDIR}/${PKGNAME}/docs
CGIBINDIR=	libexec/cgi-bin

JB_USER?=	jitter

JB_USERID?=	509

JB_GROUP?=	jitter

JB_GROUPID?=	509

JB_DATADIR=	${JB_USER}/${JB_PACKAGE}/bug_tracking
JB_CONFIGDIR=	${JB_USER}/config

JB_LOCALMAIL?=	${JB_PACKAGE}-bugs
.if !defined(JB_FQHOSTNAME)
JB_FQHOSTNAME!=	hostname
.endif
JB_HOSTNAME!=	hostname -s
JB_EMAIL?=	${JB_LOCALMAIL}@${JB_FQHOSTNAME}

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

.include "../../mk/bsd.prefs.mk"

fetch-depends:
.if !defined(JB_PACKAGE)
	@${ECHO}
	@${ECHO} "You must define the following environment variable:"
	@${ECHO} "JB_PACKAGE    -- the name of your bug category"
	@${ECHO}
	@${ECHO} "You may override the following environment variables:"
	@${ECHO} "JB_USER       -- jitterbug user (default 'jitter')"
	@${ECHO} "JB_USERID     -- jitterbug user id (default 509)"
	@${ECHO} "JB_GROUP      -- jitterbug group name (default 'jitter')"
	@${ECHO} "JB_GROUPID    -- jitterbug group id (default 509)"
	@${ECHO} "JB_FQHOSTNAME -- fully qualified host name"
	@${ECHO} "JB_LOCALMAIL  -- local mail alias for \$$JB_PACKAGE category."
	@${ECHO} "jitterbug will send and receive e-mail for \$$JB_PACKAGE"
	@${ECHO} "as \$$JB_LOCALMAIL@\$$JB_FQHOSTNAME"
	@${ECHO}
	@${FALSE}
.endif
.if (${JB_FQHOSTNAME} == ${JB_HOSTNAME})
	@${ECHO} "Warning: Could not determine your fully qualified hostname."
	@${ECHO} "You must set the JB_FQHOSTNAME environment variable."
	@${ECHO}
	@${FALSE}
.endif

pre-extract:
	@(case "X${JB_USER}" in                                               \
	Xbin|Xetc|Xinclude|Xinfo|Xlib|Xlibdata|Xlibexec|Xman|Xsbin|Xshare)    \
		gooduser=no;                                                  \
		;;                                                            \
	*)                                                                    \
		gooduser=yes;                                                 \
		;;                                                            \
	esac;                                                                 \
	if [ $$gooduser = "no" ]; then                                        \
		${ECHO} "You have choosen JB_USER=${JB_USER} which";          \
		${ECHO} "will cause trouble, because gnats would get";        \
		${ECHO} "installed to ${PREFIX}/share ${JB_USER}. So";        \
		${ECHO} "please set JB_USER to something more reasonable";    \
		${ECHO} "like 'jitter'.";                                     \
		${ECHO} "";                                                   \
		${FALSE};                                                     \
		fi)

post-patch:
	@${SED} -e 's|@PREFIX@|${PREFIX}|g'                                   \
		< ${WRKSRC}/jconfig.h                                         \
		> ${WRKSRC}/jconfig.h.tmp
	@${MV} -f ${WRKSRC}/jconfig.h.tmp ${WRKSRC}/jconfig.h

pre-install:
.if !defined(JB_USER)
	@${ECHO} "Arrrgggghhh. JB_USER not defined. Send-pr!"
	@${FALSE}
.endif
	@${SED}  \
		-e 's|@JB_USER@|${JB_USER}|g'                                 \
		-e 's|@JB_USERID@|${JB_USERID}|g'                             \
		-e 's|@JB_GROUP@|${JB_GROUP}|g'                               \
		-e 's|@JB_GROUPID@|${JB_GROUPID}|g'                           \
		-e 's|@JB_LOCALMAIL@|${JB_LOCALMAIL}|g'                       \
		-e 's|@JB_PACKAGE@|${JB_PACKAGE}|g'                           \
		-e 's|@PREFIX@|${PREFIX}|g'                                   \
		-e 's|@LOCALBASE@|${LOCALBASE}|g'                             \
		-e 's|@FILESDIR@|${FILESDIR}|g'                               \
			<${PKGDIR}/REQ                                        \
			>${REQ_FILE}
	@${SED}  \
		-e 's|@JB_DATADIR@|${JB_DATADIR}|g'                           \
		-e 's|@CGIBINDIR@|${CGIBINDIR}|g'                             \
		-e 's|@JB_PACKAGE@|${JB_PACKAGE}|g'                           \
		-e 's|@JB_USER@|${JB_USER}|g'                                 \
		-e 's|@JB_GROUP@|${JB_GROUP}|g'                               \
			<${PKGDIR}/PLIST                                      \
			>${PLIST_SRC}
	@${SED}  \
		-e 's|@JB_USER@|${JB_USER}|g'                                 \
			<${FILESDIR}/jitterbug.auth                           \
			>${WRKDIR}/jitterbug.auth
	@${SED}  \
		-e 's|@JB_USER@|${JB_USER}|g'                                 \
		-e 's|@JB_PACKAGE@|${JB_PACKAGE}|g'                           \
		-e 's|@PREFIX@|${PREFIX}|g'                                   \
			<${FILESDIR}/NEWPACKAGE                               \
			>${WRKDIR}/NEWPACKAGE
	@${SED}  \
		-e 's|@JB_USER@|${JB_USER}|g'                                 \
		-e 's|@JB_PACKAGE@|${JB_PACKAGE}|g'                           \
		-e 's|@PREFIX@|${PREFIX}|g'                                   \
			<${FILESDIR}/POSTINSTALL                              \
			>${WRKDIR}/POSTINSTALL
	${SH} ${REQ_FILE} ${PKGNAME} INSTALL

do-install:
	${MKDIR} ${PREFIX}/${JB_CONFIGDIR}
	-${MKDIR} ${PREFIX}/${JB_DATADIR}
	${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 644                     \
		${CONFIGDIR}/footer.html ${PREFIX}/${JB_CONFIGDIR}
	[ -f ${PREFIX}/${JB_DATADIR}/footer.html ] ||                         \
		${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 644             \
		${CONFIGDIR}/footer.html ${PREFIX}/${JB_DATADIR}
	${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 644                     \
		${CONFIGDIR}/guest.prefs ${PREFIX}/${JB_CONFIGDIR}
	[ -f ${PREFIX}/${JB_DATADIR}/guest.prefs ] ||                         \
		${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 644             \
		${CONFIGDIR}/guest.prefs ${PREFIX}/${JB_DATADIR}
	${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 644                     \
		${CONFIGDIR}/guestintro.html ${PREFIX}/${JB_CONFIGDIR}
	[ -f ${PREFIX}/${JB_DATADIR}/guestintro.html ] ||                     \
		${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 644             \
		${CONFIGDIR}/guestintro.html ${PREFIX}/${JB_DATADIR}
	${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 644                     \
		${CONFIGDIR}/intro.html ${PREFIX}/${JB_CONFIGDIR}
	[ -f ${PREFIX}/${JB_DATADIR}/intro.html ] ||                          \
		${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 644             \
		${CONFIGDIR}/intro.html ${PREFIX}/${JB_DATADIR}
	${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 644                     \
		${CONFIGDIR}/reportform.html ${PREFIX}/${JB_CONFIGDIR}
	[ -f ${PREFIX}/${JB_DATADIR}/reportform.html ] ||                     \
		${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 644             \
		${CONFIGDIR}/reportform.html ${PREFIX}/${JB_DATADIR}
	${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 644                     \
		${CONFIGDIR}/users ${PREFIX}/${JB_CONFIGDIR}
	[ -f ${PREFIX}/${JB_DATADIR}/users ] ||                               \
		${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 644             \
		${CONFIGDIR}/users ${PREFIX}/${JB_DATADIR}
	${INSTALL} -c -o root -g nobody -m 4710                               \
		${WRKSRC}/jitterbug ${PREFIX}/${CGIBINDIR}/${JB_PACKAGE}
	${LN} -f ${PREFIX}/${CGIBINDIR}/${JB_PACKAGE} ${PREFIX}/${CGIBINDIR}/${JB_PACKAGE}.private
	${CHOWN} root ${PREFIX}/${CGIBINDIR}/${JB_PACKAGE}.private
	${CHGRP} nobody ${PREFIX}/${CGIBINDIR}/${JB_PACKAGE}.private
	${CHMOD} 4710 ${PREFIX}/${CGIBINDIR}/${JB_PACKAGE}.private
	${MKDIR} ${PREFIX}/${JB_USER}/bin
	${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 755                     \
		${WRKSRC}/new_message ${PREFIX}/${JB_USER}/bin
	${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 644                     \
		${WRKSRC}/jitterbug ${PREFIX}/${JB_USER}/bin
	${MKDIR} ${PREFIX}/${JB_USER}/etc
	[ -f ${PREFIX}/${JB_USER}/etc ] ||                                    \
		${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 755             \
		${WRKDIR}/jitterbug.auth ${PREFIX}/${JB_USER}/etc
	${MKDIR} ${PREFIX}/${JB_USER}/doc
	${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 644                     \
		${WRKDIR}/POSTINSTALL ${PREFIX}/${JB_USER}/doc
	${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 644                     \
		${WRKDIR}/NEWPACKAGE ${PREFIX}/${JB_USER}/doc
	${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 644                     \
		${DOCSDIR}/CONFIG.txt ${PREFIX}/${JB_USER}/doc
	${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 644                     \
		${DOCSDIR}/INSTALL ${PREFIX}/${JB_USER}/doc
	${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 644                     \
		${DOCSDIR}/JitterBug.txt ${PREFIX}/${JB_USER}/doc
	${CHOWN} -R ${JB_USER} ${PREFIX}/${JB_USER}
	${CHGRP} -R ${JB_GROUP} ${PREFIX}/${JB_USER}
	-${MKDIR} ${PREFIX}/etc/jitterbug
	@${SED}                                                               \
		-e 's|@JB_EMAIL@|${JB_EMAIL}|g'                               \
		-e 's|@JB_DATADIR@|${JB_DATADIR}|g'                           \
		-e 's|@JB_USERID@|${JB_USERID}|g'                             \
		-e 's|@JB_GROUPID@|${JB_GROUPID}|g'                           \
		-e 's|@PREFIX@|${PREFIX}|g'                                   \
		<${FILESDIR}/jitterbug.config                                 \
		>${PREFIX}/${JB_CONFIGDIR}/jitterbug.config
	[ -f ${PREFIX}/etc/jitterbug/${JB_PACKAGE} ] ||                       \
		${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 644             \
		${PREFIX}/${JB_CONFIGDIR}/jitterbug.config                    \
		${PREFIX}/etc/jitterbug/${JB_PACKAGE}
	[ -f ${PREFIX}/etc/jitterbug/${JB_PACKAGE}.private ] ||               \
		${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 644             \
		${PREFIX}/${JB_CONFIGDIR}/jitterbug.config                    \
		${PREFIX}/etc/jitterbug/${JB_PACKAGE}.private

post-install:
.if !defined(BATCH)
	@${ECHO} " "
	@${ECHO} "Please observe the following POSTINSTALL notes:"
	@${ECHO} "(POSTINSTALL is also installed in ${PREFIX}/${JB_USER}/doc)"
	@${ECHO} " "
	@${ECHO} "=============================================================================="
	@${CAT} ${WRKDIR}/POSTINSTALL
	@${ECHO} " "
	@${ECHO} "=============================================================================="
	@${ECHO} " "
.endif

.include "../../mk/bsd.pkg.mk"

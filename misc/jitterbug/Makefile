# $NetBSD: Makefile,v 1.6 1999/12/17 11:11:10 agc Exp $

DISTNAME=	jitterbug-1.6.2
WRKSRC=		${WRKDIR}/${PKGNAME}/source
CATEGORIES=	misc
MASTER_SITES=	ftp://jitterbug.samba.org/pub/jitterbug/

MAINTAINER=	wennmach@netbsd.org
HOMEPAGE=	http://jitterbug.samba.org/

DEPENDS+=	addnerd-1.6:../../sysutils/addnerd
DEPENDS+=	apache-1.3.*:../../www/apache

PLIST_SRC=	${WRKDIR}/PLIST-src
REQ_FILE=	${WRKDIR}/REQ
DEINSTALL_FILE=	${WRKDIR}/DEINSTALL
MESSAGE_FILE=	${WRKDIR}/MESSAGE
CONFIGDIR=	${WRKDIR}/${PKGNAME}/config
DOCSDIR=	${WRKDIR}/${PKGNAME}/docs
CGIBINDIR=	libexec/cgi-bin

.include "../../mk/bsd.prefs.mk"

HOSTCMD=	/usr/bin/false
.if exists(/usr/sbin/host)
HOSTCMD=	/usr/sbin/host
.elif exists(/usr/bin/host)
HOSTCMD=	/usr/bin/host
.endif

JB_PACKAGE?=	test

JB_USER?=	jitter
JB_USERID?=	509

JB_GROUP?=	jitter
JB_GROUPID?=	509

JB_DATADIR=	${JB_USER}/${JB_PACKAGE}/bug_tracking
JB_CONFIGDIR=	${JB_USER}/config

JB_LOCALMAIL?=	${JB_PACKAGE}-bugs

.if !defined(JB_FQHOSTNAME)
<<<<<<< Makefile
JB_HOSTNAME!=	/bin/hostname
JB_FQHOSTNAME!=	${NSLOOKUP} ${JB_HOSTNAME} | /usr/bin/awk '/^Name: / { print $$2; exit }'
=======
JB_FQHOSTNAME!=	(${HOSTCMD} `/bin/hostname` 2>/dev/null || echo totally.unknown.domain) | /usr/bin/awk '{ print $$1; exit }'
>>>>>>> 1.5
.endif
JB_EMAIL?=	${JB_LOCALMAIL}@${JB_FQHOSTNAME}

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

pre-extract:
.if ${JB_FQHOSTNAME} == "totally.unknown.domain"
	@${ECHO}
	@${ECHO} "Warning: could not determine your fully qualified host"
	@${ECHO} "         name. Please set the JB_FQHOSTNAME environment"
	@${ECHO} "         variable accordingly and/or fix your name server."
	@${ECHO} "         Building for domain 'totally.unknown.domain'"
.endif
.if ${JB_PACKAGE} == "test"
	@${ECHO}
	@${ECHO} "You should define the JB_PACKAGE environment variable:"
	@${ECHO} "JB_PACKAGE    -- the name of your bug category"
	@${ECHO}
	@${ECHO} "pkgsrc will build jitterbug with \$$JB_PACKAGE = \"test\""
	@${ECHO} "so that you can easily evaluate this package."
	@${ECHO} "If you decide to use jitterbug for a real application"
	@${ECHO} "you can safly deinstall jitterbug and reinstall it with"
	@${ECHO} "\$$JB_PACKAGE set to something more senseful."
	@${ECHO}
	@${ECHO} "You may override the following environment variables:"
	@${ECHO} "JB_USER       -- jitterbug user (default='${JB_USER}')"
	@${ECHO} "JB_USERID     -- jitterbug user id (default=${JB_USERID})"
	@${ECHO} "JB_GROUP      -- jitterbug group name (default='${JB_GROUP}')"
	@${ECHO} "JB_GROUPID    -- jitterbug group id (default=${JB_GROUPID})"
	@${ECHO} "JB_FQHOSTNAME -- fully qualified host name"
	@${ECHO} "JB_LOCALMAIL  -- local mail alias for \$$JB_PACKAGE category."
	@${ECHO} "jitterbug will send and receive e-mail for \$$JB_PACKAGE"
	@${ECHO} "as '\$$JB_LOCALMAIL'@${JB_FQHOSTNAME}"
	@${ECHO}
.endif
.if ${JB_FQHOSTNAME} == ${JB_HOSTNAME}
	@${ECHO} "Warning: Could not determine your fully qualified hostname."
	@${ECHO} "You must set the JB_FQHOSTNAME environment variable."
	@${ECHO}
	@${FALSE}
.endif
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
	@${SED}                                                               \
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
	@${SED}                                                               \
		-e 's|@JB_DATADIR@|${JB_DATADIR}|g'                           \
		-e 's|@CGIBINDIR@|${CGIBINDIR}|g'                             \
		-e 's|@JB_PACKAGE@|${JB_PACKAGE}|g'                           \
		-e 's|@JB_USER@|${JB_USER}|g'                                 \
		-e 's|@JB_GROUP@|${JB_GROUP}|g'                               \
			<${PKGDIR}/PLIST                                      \
			>${PLIST_SRC}
	@${SED}                                                               \
		-e 's|@JB_USER@|${JB_USER}|g'                                 \
			<${FILESDIR}/jitterbug.auth                           \
			>${WRKDIR}/jitterbug.auth
	@${SED}                                                               \
		-e 's|@JB_USER@|${JB_USER}|g'                                 \
		-e 's|@JB_PACKAGE@|${JB_PACKAGE}|g'                           \
		-e 's|@PREFIX@|${PREFIX}|g'                                   \
			<${FILESDIR}/NEWPACKAGE                               \
			>${WRKDIR}/NEWPACKAGE
	@${SED}                                                               \
		-e 's|@JB_USER@|${JB_USER}|g'                                 \
		-e 's|@JB_PACKAGE@|${JB_PACKAGE}|g'                           \
		-e 's|@PREFIX@|${PREFIX}|g'                                   \
			<${PKGDIR}/MESSAGE                                    \
			>${MESSAGE_FILE}
	@${SED}                                                               \
		-e 's|@JB_USER@|${JB_USER}|g'                                 \
		-e 's|@JB_GROUP@|${JB_GROUP}|g'                               \
		-e 's|@JB_PACKAGE@|${JB_PACKAGE}|g'                           \
		-e 's|@PREFIX@|${PREFIX}|g'                                   \
			<${PKGDIR}/DEINSTALL                                  \
			>${DEINSTALL_FILE}
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
		${MESSAGE_FILE} ${PREFIX}/${JB_USER}/doc/POSTINSTALL
	${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 644                     \
		${WRKDIR}/NEWPACKAGE ${PREFIX}/${JB_USER}/doc
	${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 644                     \
		${DOCSDIR}/CONFIG.txt ${PREFIX}/${JB_USER}/doc
	${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 644                     \
		${DOCSDIR}/INSTALL ${PREFIX}/${JB_USER}/doc
	${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 644                     \
		${DOCSDIR}/JitterBug.txt ${PREFIX}/${JB_USER}/doc
	@${SED}                                                               \
		-e 's|@JB_EMAIL@|${JB_EMAIL}|g'                               \
		-e 's|@JB_DATADIR@|${JB_DATADIR}|g'                           \
		-e 's|@JB_USERID@|${JB_USERID}|g'                             \
		-e 's|@JB_GROUPID@|${JB_GROUPID}|g'                           \
		-e 's|@PREFIX@|${PREFIX}|g'                                   \
		<${FILESDIR}/jitterbug.config                                 \
		>${PREFIX}/${JB_CONFIGDIR}/jitterbug.config
	${CHOWN} -R ${JB_USER} ${PREFIX}/${JB_USER}
	${CHGRP} -R ${JB_GROUP} ${PREFIX}/${JB_USER}
	-${MKDIR} ${PREFIX}/etc/jitterbug
	[ -f ${PREFIX}/etc/jitterbug/${JB_PACKAGE} ] ||                       \
		${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 644             \
		${PREFIX}/${JB_CONFIGDIR}/jitterbug.config                    \
		${PREFIX}/etc/jitterbug/${JB_PACKAGE}
	[ -f ${PREFIX}/etc/jitterbug/${JB_PACKAGE}.private ] ||               \
		${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 644             \
		${PREFIX}/${JB_CONFIGDIR}/jitterbug.config                    \
		${PREFIX}/etc/jitterbug/${JB_PACKAGE}.private

.include "../../mk/bsd.pkg.mk"

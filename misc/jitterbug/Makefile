# $NetBSD: Makefile,v 1.34.4.1 2012/04/08 09:18:55 sbd Exp $

DISTNAME=	jitterbug-1.6.2
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	ftp://jitterbug.samba.org/pub/jitterbug/

MAINTAINER=	wennmach@NetBSD.org
HOMEPAGE=	http://jitterbug.samba.org/
COMMENT=	Web-oriented bug-tracking tool

PKG_DESTDIR_SUPPORT=	destdir

BROKEN=	Not buildable and dead upstream.

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}/source
CONFIGDIR=	${WRKDIR}/${PKGNAME_NOREV}/config
DOCSDIR=	${WRKDIR}/${PKGNAME_NOREV}/docs
CGIBINDIR=	libexec/cgi-bin

.include "../../mk/bsd.prefs.mk"

JB_PACKAGE?=	test

JB_USER?=	jitter
JB_USERID?=	509

JB_GROUP?=	jitter
JB_GROUPID?=	509

JB_DATADIR=	${JB_USER}/${JB_PACKAGE}/bug_tracking
JB_CONFIGDIR=	${JB_USER}/config

JB_LOCALMAIL?=	${JB_PACKAGE}-bugs

JB_HOSTNAME!=	${UNAME} -n
JB_SHORTNAME=	${JB_HOSTNAME:C/\..*//}
.if !defined(JB_FQHOSTNAME)
JB_FQHOSTNAME=	${JB_HOSTNAME}
.endif
JB_EMAIL?=	${JB_LOCALMAIL}@${JB_FQHOSTNAME}

PKG_GROUPS=		${JB_GROUP}
PKG_GID.${JB_GROUP}=	${JB_GROUPID}
PKG_UID.${JB_USER}=	${JB_USERID}
PKG_USERS=		${JB_USER}:${JB_GROUP}

PKG_GROUPS_VARS+=	JB_GROUP
PKG_USERS_VARS+=	JB_USER

USERGROUP_PHASE=	pre-install

GNU_CONFIGURE=	yes

MESSAGE_SUBST+=	JB_USER=${JB_USER:Q}		\
		JB_PACKAGE=${JB_PACKAGE:Q}	\
		JB_LOCALMAIL=${JB_LOCALMAIL:Q}

PLIST_SUBST+=	JB_DATADIR=${JB_DATADIR:Q}
PLIST_SUBST+=	CGIBINDIR=${CGIBINDIR:Q}
PLIST_SUBST+=	JB_PACKAGE=${JB_PACKAGE:Q}
PLIST_SUBST+=	JB_USER=${JB_USER:Q}
PLIST_SUBST+=	JB_GROUP=${JB_GROUP:Q}

FILES_SUBST+=	JB_USER=${JB_USER} JB_USERID=${JB_USERID}		\
		JB_GROUP=${JB_GROUP} JB_GROUPID=${JB_GROUPID}		\
		JB_PACKAGE=${JB_PACKAGE}				\
		ADDUSER=${ADDUSER} ADDGROUP=${ADDGROUP}			\
		CHGRP=${CHGRP} ID=${ID} TOUCH=${TOUCH} RM=${RM}

pre-extract:
	@(if [ "X${JB_HOSTNAME}" = "X${JB_SHORTNAME}" ]; then                 \
	${ECHO};                                                              \
	${ECHO} "Warning: could not determine your fully qualified host";     \
	${ECHO} "         name. Please set the JB_FQHOSTNAME environment";    \
	${ECHO} "         variable or set the correct fully qualified";       \
	${ECHO} "         domain name in ${PREFIX}/${JB_CONFIGDIR}/jitterbug.config"; \
	${ECHO} "         after installation.";                               \
	fi)
.if ${JB_PACKAGE} == "test"
	@${ECHO}
	@${ECHO} "You should define the JB_PACKAGE environment variable:"
	@${ECHO} "JB_PACKAGE    -- the name of your bug category"
	@${ECHO}
	@${ECHO} "pkgsrc will build jitterbug with \$$JB_PACKAGE = \"test\""
	@${ECHO} "so that you can easily evaluate this package."
	@${ECHO} "If you decide to use jitterbug for a real application"
	@${ECHO} "you can safely deinstall jitterbug and reinstall it with"
	@${ECHO} "\$$JB_PACKAGE set to something more senseful."
	@${ECHO}
	@${ECHO} "You may override the following environment variables:"
	@${ECHO} "JB_USER       -- jitterbug user (default='${JB_USER}')"
	@${ECHO} "JB_USERID     -- jitterbug user id (default=${JB_USERID})"
	@${ECHO} "JB_GROUP      -- jitterbug group name (default='${JB_GROUP}')"
	@${ECHO} "JB_GROUPID    -- jitterbug group id (default=${JB_GROUPID})"
	@${ECHO} "JB_FQHOSTNAME -- fully qualified host name"
	@${ECHO} "JB_LOCALMAIL  -- local mail alias for \$$JB_PACKAGE category."
	@${ECHO}
	@${ECHO} "jitterbug will send and receive e-mail for \$$JB_PACKAGE"
	@${ECHO} "  as '\$$JB_LOCALMAIL'@${JB_FQHOSTNAME}"
	@${ECHO} "  (default='${JB_LOCALMAIL}@${JB_FQHOSTNAME}')"
	@${ECHO}
.endif
.if ${JB_FQHOSTNAME} == ${JB_SHORTNAME}
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
	@${ECHO} "Arrrgggghhh. JB_USER not defined. Please send-pr!"
	@${FALSE}
.endif
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
	@${SED}								      \
		-e 's|@JB_PACKAGE@|${JB_PACKAGE}|g'			      \
		-e 's|@JB_USER@|${JB_USER}|g'				      \
		-e 's|@PREFIX@|${PREFIX}|g'				      \
			< ${FILESDIR}/httpd.conf			      \
			> ${WRKDIR}/httpd.conf

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${JB_CONFIGDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${JB_DATADIR}
	${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 644                     \
		${CONFIGDIR}/footer.html ${DESTDIR}${PREFIX}/${JB_CONFIGDIR}
	[ -f ${DESTDIR}${PREFIX}/${JB_DATADIR}/footer.html ] ||               \
		${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 644             \
		${CONFIGDIR}/footer.html ${DESTDIR}${PREFIX}/${JB_DATADIR}
	${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 644                     \
		${CONFIGDIR}/guest.prefs ${DESTDIR}${PREFIX}/${JB_CONFIGDIR}
	[ -f ${DESTDIR}${PREFIX}/${JB_DATADIR}/guest.prefs ] ||               \
		${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 644             \
		${CONFIGDIR}/guest.prefs ${DESTDIR}${PREFIX}/${JB_DATADIR}
	${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 644                     \
		${CONFIGDIR}/guestintro.html ${DESTDIR}${PREFIX}/${JB_CONFIGDIR}
	[ -f ${DESTDIR}${PREFIX}/${JB_DATADIR}/guestintro.html ] ||           \
		${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 644             \
		${CONFIGDIR}/guestintro.html ${DESTDIR}${PREFIX}/${JB_DATADIR}
	${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 644                     \
		${CONFIGDIR}/intro.html ${DESTDIR}${PREFIX}/${JB_CONFIGDIR}
	[ -f ${DESTDIR}${PREFIX}/${JB_DATADIR}/intro.html ] ||                \
		${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 644             \
		${CONFIGDIR}/intro.html ${DESTDIR}${PREFIX}/${JB_DATADIR}
	${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 644                     \
		${CONFIGDIR}/reportform.html ${DESTDIR}${PREFIX}/${JB_CONFIGDIR}
	[ -f ${DESTDIR}${PREFIX}/${JB_DATADIR}/reportform.html ] ||           \
		${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 644             \
		${CONFIGDIR}/reportform.html ${DESTDIR}${PREFIX}/${JB_DATADIR}
	${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 644                     \
		${CONFIGDIR}/users ${DESTDIR}${PREFIX}/${JB_CONFIGDIR}
	[ -f ${DESTDIR}${PREFIX}/${JB_DATADIR}/users ] ||                     \
		${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 644             \
		${CONFIGDIR}/users ${DESTDIR}${PREFIX}/${JB_DATADIR}
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/${CGIBINDIR}
	${INSTALL} -c -o ${ROOT_USER} -g nobody -m 4710                       \
		${WRKSRC}/jitterbug ${DESTDIR}${PREFIX}/${CGIBINDIR}/${JB_PACKAGE}
	${LN} -f ${DESTDIR}${PREFIX}/${CGIBINDIR}/${JB_PACKAGE}               \
	         ${DESTDIR}${PREFIX}/${CGIBINDIR}/${JB_PACKAGE}.private
	${CHOWN} ${ROOT_USER} ${DESTDIR}${PREFIX}/${CGIBINDIR}/${JB_PACKAGE}.private
	${CHGRP} nobody ${DESTDIR}${PREFIX}/${CGIBINDIR}/${JB_PACKAGE}.private
	${CHMOD} 4710 ${DESTDIR}${PREFIX}/${CGIBINDIR}/${JB_PACKAGE}.private
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/${JB_USER}/bin
	${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 755                     \
		${WRKSRC}/new_message ${DESTDIR}${PREFIX}/${JB_USER}/bin
	${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 644                     \
		${WRKSRC}/jitterbug ${DESTDIR}${PREFIX}/${JB_USER}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${JB_USER}/etc
	[ -f ${DESTDIR}${PREFIX}/${JB_USER}/etc ] ||                          \
		${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 755             \
		${WRKDIR}/jitterbug.auth ${DESTDIR}${PREFIX}/${JB_USER}/etc
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${JB_USER}/doc
	${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 644                     \
		${WRKDIR}/NEWPACKAGE ${DESTDIR}${PREFIX}/${JB_USER}/doc
	${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 644                     \
		${DOCSDIR}/CONFIG.txt ${DESTDIR}${PREFIX}/${JB_USER}/doc
	${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 644                     \
		${DOCSDIR}/INSTALL ${DESTDIR}${PREFIX}/${JB_USER}/doc
	${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 644                     \
		${DOCSDIR}/JitterBug.txt ${DESTDIR}${PREFIX}/${JB_USER}/doc
	@${SED}                                                               \
		-e 's|@JB_EMAIL@|${JB_EMAIL}|g'                               \
		-e 's|@JB_DATADIR@|${JB_DATADIR}|g'                           \
		-e 's|@JB_USERID@|${JB_USERID}|g'                             \
		-e 's|@JB_GROUPID@|${JB_GROUPID}|g'                           \
		-e 's|@PREFIX@|${PREFIX}|g'                                   \
		<${FILESDIR}/jitterbug.config                                 \
		>${DESTDIR}${PREFIX}/${JB_CONFIGDIR}/jitterbug.config
	${CHOWN} -R ${JB_USER} ${DESTDIR}${PREFIX}/${JB_USER}
	${CHGRP} -R ${JB_GROUP} ${DESTDIR}${PREFIX}/${JB_USER}
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/etc/jitterbug
	[ -f ${DESTDIR}${PREFIX}/etc/jitterbug/${JB_PACKAGE} ] ||             \
		${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 644             \
		${DESTDIR}${PREFIX}/${JB_CONFIGDIR}/jitterbug.config          \
		${DESTDIR}${PREFIX}/etc/jitterbug/${JB_PACKAGE}
	[ -f ${DESTDIR}${PREFIX}/etc/jitterbug/${JB_PACKAGE}.private ] ||     \
		${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 644             \
		${DESTDIR}${PREFIX}/${JB_CONFIGDIR}/jitterbug.config          \
		${DESTDIR}${PREFIX}/etc/jitterbug/${JB_PACKAGE}.private
	${INSTALL} -c -o ${JB_USER} -g ${JB_GROUP} -m 644        	      \
		${WRKDIR}/httpd.conf			                      \
		${DESTDIR}${PREFIX}/etc/jitterbug/httpd.conf.add

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.57 2011/12/04 23:37:14 riz Exp $
#

DISTNAME=	monotone-1.0
PKGNAME=	${DISTNAME:S/-/-server-/}
CATEGORIES=	devel scm
MASTER_SITES=	http://monotone.ca/downloads/1.0/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://monotone.ca/
COMMENT=	Simplifies the configuration of a dedicated Monotone server

DEPENDS+=	digest>=20080510:../../pkgtools/digest
DEPENDS+=	monotone>=1.0:../../devel/monotone

PKG_DESTDIR_SUPPORT=	user-destdir

LICENSE=	2-clause-bsd
NO_BUILD=	yes
NO_CHECKSUM=	yes

RCD_SCRIPTS=		monotone

PKG_SYSCONFSUBDIR=	monotone-server
OWN_DIRS_PERMS=	${PKG_SYSCONFDIR}/keys \
			${MONOTONE_USER} ${MONOTONE_GROUP} 700

EXAMPLEDIR=		${PREFIX}/share/examples/monotone-server
CONF_FILES_PERMS=	${EXAMPLEDIR}/monotonerc \
			${PKG_SYSCONFDIR}/monotonerc \
			${MONOTONE_USER} ${MONOTONE_GROUP} 600
CONF_FILES_PERMS+=	${EXAMPLEDIR}/read-permissions \
			${PKG_SYSCONFDIR}/read-permissions \
			${MONOTONE_USER} ${MONOTONE_GROUP} 600
CONF_FILES_PERMS+=	${EXAMPLEDIR}/write-permissions \
			${PKG_SYSCONFDIR}/write-permissions \
			${MONOTONE_USER} ${MONOTONE_GROUP} 600
CONF_FILES_PERMS+=	/dev/null ${MONOTONE_LOGFILE} \
			${MONOTONE_USER} ${MONOTONE_GROUP} 600

PKG_GROUPS=		${MONOTONE_GROUP}
PKG_USERS=		${MONOTONE_USER}:${MONOTONE_GROUP}

PKG_GROUPS_VARS+=	MONOTONE_GROUP
PKG_USERS_VARS+=	MONOTONE_USER

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		RCD_SCRIPTS_DIR VARBASE

MONOTONE_HOME=		${VARBASE}/monotone
MONOTONE_LOGFILE=	${VARBASE}/log/monotone.log

PKG_GECOS.${MONOTONE_USER}=	Monotone dedicated server
PKG_HOME.${MONOTONE_USER}=	${MONOTONE_HOME}
PKG_SHELL.${MONOTONE_USER}=	${SH}

SUBST_CLASSES+=	vars
SUBST_STAGE.vars=	do-configure
SUBST_MESSAGE.vars=	Configuring sources.
SUBST_FILES.vars=	${WRKDIR}/monotone-server.7
SUBST_SED.vars+=	-e 's|@MONOTONE_HOME@|${MONOTONE_HOME}|g'
SUBST_SED.vars+=	-e 's|@MONOTONE_LOGFILE@|${MONOTONE_LOGFILE}|g'
SUBST_SED.vars+=	-e 's|@MONOTONE_USER@|${MONOTONE_USER}|g'
SUBST_SED.vars+=	-e 's|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g'
SUBST_SED.vars+=	-e 's|@PREFIX@|${PREFIX}|g'
SUBST_SED.vars+=	-e 's|@RCD_SCRIPTS_DIR@|${RCD_SCRIPTS_DIR}|g'

FILES_SUBST+=		DIGEST=${PREFIX:Q}/bin/digest
FILES_SUBST+=		MONOTONE=${PREFIX:Q}/bin/mtn
FILES_SUBST+=		MONOTONE_GROUP=${MONOTONE_GROUP:Q}
FILES_SUBST+=		MONOTONE_LOGFILE=${MONOTONE_LOGFILE:Q}
FILES_SUBST+=		MONOTONE_USER=${MONOTONE_USER:Q}
FILES_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}

INSTALLATION_DIRS=	${PKGMANDIR}/man7

post-extract:
.for f in monotone-server.7 read-permissions write-permissions
	${CP} ${FILESDIR}/${f} ${WRKDIR}
.endfor

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKDIR}/monotone-server.7 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man7/monotone-server.7
	${INSTALL_DATA} ${WRKSRC}/extra/mtn-hooks/get_passphrase_from_file.lua \
		${DESTDIR}${EXAMPLEDIR}/monotonerc
	${INSTALL_DATA} ${WRKDIR}/read-permissions \
		${DESTDIR}${EXAMPLEDIR}/read-permissions
	${INSTALL_DATA} ${WRKDIR}/write-permissions \
		${DESTDIR}${EXAMPLEDIR}/write-permissions

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.36 2007/12/14 11:39:38 bjs Exp $
#

DISTNAME=	monotone-server-0.38
CATEGORIES=	devel scm
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://monotone.ca/
COMMENT=	Simplifies the configuration of a dedicated Monotone server

DEPENDS+=	monotone>=0.38:../../devel/monotone

EXTRACT_ONLY=	# empty
NO_BUILD=	yes
NO_CHECKSUM=	yes
WRKSRC=		${WRKDIR}

RCD_SCRIPTS=		monotone

PKG_SYSCONFSUBDIR=	monotone-server
OWN_DIRS_PERMS=		${PKG_SYSCONFDIR}/keys \
			${MONOTONE_USER} ${MONOTONE_GROUP} 700

EXAMPLEDIR=		${PREFIX}/share/examples/monotone-server
CONF_FILES_PERMS=	${EXAMPLEDIR}/hooks.conf \
			${PKG_SYSCONFDIR}/hooks.conf \
			${MONOTONE_USER} ${MONOTONE_GROUP} 600
CONF_FILES_PERMS+=	${EXAMPLEDIR}/read-permissions \
			${PKG_SYSCONFDIR}/read-permissions \
			${MONOTONE_USER} ${MONOTONE_GROUP} 600
CONF_FILES_PERMS+=	${EXAMPLEDIR}/write-permissions \
			${PKG_SYSCONFDIR}/write-permissions \
			${MONOTONE_USER} ${MONOTONE_GROUP} 600

PKG_GROUPS=		${MONOTONE_GROUP}
PKG_USERS=		${MONOTONE_USER}:${MONOTONE_GROUP}

PKG_GROUPS_VARS+=	MONOTONE_GROUP
PKG_USERS_VARS+=	MONOTONE_USER

.include "../../mk/bsd.prefs.mk"

PKG_GECOS.${MONOTONE_USER}=	Monotone dedicated server
PKG_HOME.${MONOTONE_USER}=	${VARBASE}/monotone
PKG_SHELL.${MONOTONE_USER}=	${SH}

SUBST_CLASSES+=		vars
SUBST_STAGE.vars=	do-configure
SUBST_MESSAGE.vars=	Configuring sources.
SUBST_FILES.vars=	*
SUBST_SED.vars=		-e 's|@MONOTONE@|${PREFIX}/bin/mtn|g'
SUBST_SED.vars+=	-e 's|@MONOTONE_GROUP@|${MONOTONE_GROUP}|g'
SUBST_SED.vars+=	-e 's|@MONOTONE_USER@|${MONOTONE_USER}|g'
SUBST_SED.vars+=	-e 's|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g'
SUBST_SED.vars+=	-e 's|@SH@|${SH}|g'
SUBST_SED.vars+=	-e 's|@VARBASE@|${VARBASE}|g'

FILES_SUBST+=		MONOTONE_GROUP=${MONOTONE_GROUP:Q}
FILES_SUBST+=		MONOTONE_USER=${MONOTONE_USER:Q}

INSTALLATION_DIRS=	sbin

do-extract:
.for f in hooks.conf monotone-server-init.sh read-permissions \
          write-permissions
	${CP} ${FILESDIR}/${f} ${WRKSRC}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/monotone-server-init.sh \
		${PREFIX}/sbin/monotone-server-init
	${INSTALL_DATA_DIR} ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/hooks.conf ${EXAMPLEDIR}/hooks.conf
	${INSTALL_DATA} ${WRKSRC}/read-permissions \
		${EXAMPLEDIR}/read-permissions
	${INSTALL_DATA} ${WRKSRC}/write-permissions \
		${EXAMPLEDIR}/write-permissions

.include "../../mk/bsd.pkg.mk"

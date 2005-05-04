# $NetBSD: Makefile,v 1.5 2005/05/04 12:18:09 jmmv Exp $
#

DISTNAME=	monotone-server-0.19
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.venge.net/monotone/
COMMENT=	Simplifies the configuration of a dedicated Monotone server

DEPENDS+=	monotone>=0.19:../../devel/monotone

EXTRACT_ONLY=	# empty
NO_BUILD=	yes
NO_CHECKSUM=	yes
USE_PKGINSTALL=	yes
WRKSRC=		${WRKDIR}

RCD_SCRIPTS=		monotone

PKG_SYSCONFSUBDIR=	monotone-server

BUILD_DEFS+=		MONOTONE_GROUP MONOTONE_USER

EXAMPLEDIR=		${PREFIX}/share/examples/monotone-server
CONF_FILES_PERMS=	${EXAMPLEDIR}/branches.conf \
			${PKG_SYSCONFDIR}/branches.conf \
			${MONOTONE_USER} ${MONOTONE_GROUP} 600
CONF_FILES_PERMS+=	${EXAMPLEDIR}/hooks.conf \
			${PKG_SYSCONFDIR}/hooks.conf \
			${MONOTONE_USER} ${MONOTONE_GROUP} 600

PKG_USERS=		${MONOTONE_USER}:${MONOTONE_GROUP}::Monotone\\ dedicated\\ server:${VARBASE}/monotone:${SH}
PKG_GROUPS=		${MONOTONE_GROUP}

SUBST_CLASSES+=		vars
SUBST_STAGE.vars=	do-configure
SUBST_MESSAGE.vars=	"Configuring sources."
SUBST_FILES.vars=	${WRKSRC}/*
SUBST_SED.vars=		-e 's|@MONOTONE@|${PREFIX}/bin/monotone|g'
SUBST_SED.vars+=	-e 's|@MONOTONE_GROUP@|${MONOTONE_GROUP}|g'
SUBST_SED.vars+=	-e 's|@MONOTONE_USER@|${MONOTONE_USER}|g'
SUBST_SED.vars+=	-e 's|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g'
SUBST_SED.vars+=	-e 's|@SH@|${SH}|g'
SUBST_SED.vars+=	-e 's|@VARBASE@|${VARBASE}|g'

FILES_SUBST+=		MONOTONE_GROUP=${MONOTONE_GROUP}
FILES_SUBST+=		MONOTONE_USER=${MONOTONE_USER}

INSTALLATION_DIRS=	sbin

do-extract:
.for f in branches.conf hooks.conf monotone-server-init.sh
	${CP} ${FILESDIR}/${f} ${WRKSRC}
.endfor
.undef f

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/monotone-server-init.sh \
		${PREFIX}/sbin/monotone-server-init
	${INSTALL_DATA_DIR} ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/branches.conf ${EXAMPLEDIR}/branches.conf
	${INSTALL_DATA} ${WRKSRC}/hooks.conf ${EXAMPLEDIR}/hooks.conf

.include "../../mk/bsd.pkg.mk"

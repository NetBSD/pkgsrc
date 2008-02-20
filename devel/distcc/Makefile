# $NetBSD: Makefile,v 1.32 2008/02/20 10:16:52 rillig Exp $

PKGNAME=		${DISTNAME}
PKGREVISION=		2
COMMENT=		Tool for distributed C/C++ compiling

.include "Makefile.common"

PKG_SYSCONFSUBDIR=	distcc
RCD_SCRIPTS=		distccd

CHECK_PORTABILITY_SKIP+=	contrib/redhat/init

.include "../../mk/bsd.prefs.mk"

DISTCC_USER?=		distcc
DISTCC_GROUP?=		distcc
PKG_GROUPS=		${DISTCC_GROUP}
PKG_USERS=		${DISTCC_USER:Q}:${DISTCC_GROUP:Q}
PKG_GROUPS_VARS+=	DISTCC_GROUP
PKG_USERS_VARS+=	DISTCC_USER

DISTCC_PIDDIR?=		${VARBASE}/run/distccd
OWN_DIRS_PERMS=		${DISTCC_PIDDIR} ${DISTCC_USER:Q} ${DISTCC_GROUP:Q} 0750

FILES_SUBST+=		DISTCC_PIDDIR=${DISTCC_PIDDIR:Q}
FILES_SUBST+=		DISTCC_USER=${DISTCC_USER:Q}
FILES_SUBST+=		DISTCC_GROUP=${DISTCC_GROUP:Q}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX:Q}/share/distcc

.include "../../mk/bsd.pkg.mk"

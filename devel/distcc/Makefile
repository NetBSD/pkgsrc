# $NetBSD: Makefile,v 1.28 2006/02/17 07:38:45 martti Exp $

PKGNAME=		${DISTNAME}
PKGREVISION=		2
COMMENT=		Tool for distributed C/C++ compiling

.include "Makefile.common"

PKG_SYSCONFSUBDIR=	distcc
RCD_SCRIPTS=		distccd

.include "../../mk/bsd.prefs.mk"

DISTCC_USER?=		distcc
DISTCC_GROUP?=		distcc
PKG_GROUPS=		${DISTCC_GROUP}
PKG_USERS=		${DISTCC_USER:Q}:${DISTCC_GROUP:Q}::Distccd\ user

DISTCC_PIDDIR?=		${VARBASE}/run/distccd
OWN_DIRS_PERMS=		${DISTCC_PIDDIR} ${DISTCC_USER:Q} ${DISTCC_GROUP:Q} 0750

FILES_SUBST+=		DISTCC_PIDDIR=${DISTCC_PIDDIR:Q}
FILES_SUBST+=		DISTCC_USER=${DISTCC_USER:Q}
FILES_SUBST+=		DISTCC_GROUP=${DISTCC_GROUP:Q}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX:Q}/share/distcc

.include "../../mk/bsd.pkg.mk"

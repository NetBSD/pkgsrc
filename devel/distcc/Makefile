# $NetBSD: Makefile,v 1.27 2006/02/05 23:08:41 joerg Exp $

PKGNAME=		${DISTNAME}
PKGREVISION=		2
COMMENT=		Tool for distributed C/C++ compiling

.include "Makefile.common"

PKG_SYSCONFSUBDIR=	distcc
RCD_SCRIPTS=		distccd

DISTCC_USER?=		distcc
DISTCC_GROUP?=		distcc
PKG_GROUPS=		${DISTCC_GROUP}
PKG_USERS=		${DISTCC_USER}:${DISTCC_GROUP}::Distccd\ user

DISTCC_PIDDIR?=		${VARBASE}/run/distccd
OWN_DIRS_PERMS=		${DISTCC_PIDDIR} ${DISTCC_USER} ${DISTCC_GROUP} 0750

FILES_SUBST+=		DISTCC_PIDDIR=${DISTCC_PIDDIR:Q}
FILES_SUBST+=		DISTCC_USER=${DISTCC_USER:Q}
FILES_SUBST+=		DISTCC_GROUP=${DISTCC_GROUP:Q}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/distcc

.include "../../mk/bsd.pkg.mk"

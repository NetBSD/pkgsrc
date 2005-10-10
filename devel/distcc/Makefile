# $NetBSD: Makefile,v 1.25 2005/10/10 09:53:07 jmmv Exp $

PKGNAME=		${DISTNAME}
PKGREVISION=		1
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

FILES_SUBST+=		DISTCC_PIDDIR=${DISTCC_PIDDIR}
FILES_SUBST+=		DISTCC_USER=${DISTCC_USER}
FILES_SUBST+=		DISTCC_GROUP=${DISTCC_GROUP}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/distcc

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.1 2018/09/02 09:53:14 triaxx Exp $

DISTNAME=	taskd-1.1.0
PKGNAME=	${DISTNAME:S/taskd/taskserver/}
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	https://taskwarrior.org/download/

MAINTAINER=	esg@sdf.org
HOMEPAGE=	https://taskwarrior.org/download/
COMMENT=	Lightweight, secure server providing access to task data
LICENSE=	mit

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DTASKD_MAN1DIR=${PREFIX}/${PKGMANDIR}/man1
CMAKE_ARGS+=	-DTASKD_MAN5DIR=${PREFIX}/${PKGMANDIR}/man5

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../mk/bsd.prefs.mk"
SMF_NAME=	taskd
TASKD_USER?=	taskd
TASKD_GROUP?=	taskd
TASKD_DATA?=	${VARBASE}/taskd
PKG_GROUPS=	${TASKD_GROUP}
PKG_USERS=	${TASKD_USER}:${TASKD_GROUP}
PKG_GROUPS_VARS=	TASKD_USER
PKG_USERS_VARS=	TASKD_GROUP
PKG_HOME.${TASKD_USER}=	${TASKD_DATA}

FILES_SUBST+=	TASKD_USER=${TASKD_USER} TASKD_GROUP=${TASKD_GROUP} \
		TASKD_DATA=${TASKD_DATA}
MESSAGE_SUBST+=	TASKD_DATA=${TASKD_DATA}

EGDIR=			${PREFIX}/share/examples/taskd
EGFILES+=		pki/README pki/generate pki/generate.ca \
			pki/generate.client pki/generate.crl \
			pki/generate.server pki/vars
INSTALLATION_DIRS+=	${EGDIR}/pki

BUILD_DEFS+=	TASKD_USER TASKD_GROUP TASKD_DATA VARBASE

REPLACE_SH=	src/taskdctl

MAKE_DIRS=		+	${TASKD_DATA}
OWN_DIRS_PERMS+=	${TASKD_DATA} ${TASKD_USER} ${TASKD_GROUP} 0750

RCD_SCRIPTS=	taskd

post-install:
.for file in ${EGFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DESTDIR}${EGDIR}/${file}
.endfor

.include "../../devel/libuuid/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

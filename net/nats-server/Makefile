# $NetBSD: Makefile,v 1.41 2024/06/13 13:47:04 bsiegert Exp $
#

DISTNAME=		nats-server-2.1.9
PKGREVISION=		40
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GITHUB:=nats-io/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

HOMEPAGE=		https://nats.io/
COMMENT=		Simple, secure and high performance messaging system
LICENSE=		apache-2.0

BUILD_DEFS+=		VARBASE

GO_BUILD_PATTERN=	.

NATS_USER=		natssrv
NATS_GROUP=		natssrv
NATS_HOMEDIR=		${VARBASE}/nats-server
NATS_LOGDIR=		${VARBASE}/log/nats-server
NATS_LOGFILE=		${NATS_LOGDIR}/nats-server.log

CHECK_SSP_SKIP=		bin/*

.include "go-modules.mk"

.include "../../mk/bsd.prefs.mk"

PKG_GROUPS=	${NATS_GROUP}
PKG_USERS=	${NATS_USER}:${NATS_GROUP}

PKG_HOME.${NATS_USER}=		${NATS_HOMEDIR}
PKG_GECOS.${NATS_USER}=		nats.io server
PKG_SHELL.${NATS_USER}=		/bin/sh

RCD_SCRIPTS=		nats_server
SMF_NAME=		nats-server
SMF_METHODS=		nats-server

FILES_SUBST+=		NATS_USER=${NATS_USER}
FILES_SUBST+=		NATS_GROUP=${NATS_GROUP}
FILES_SUBST+=		NATS_HOMEDIR=${NATS_HOMEDIR}
FILES_SUBST+=		NATS_LOGDIR=${NATS_LOGDIR}
FILES_SUBST+=		NATS_LOGFILE=${NATS_LOGFILE}
FILES_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

EGDIR=			${PREFIX}/share/examples/nats-server
REQD_FILES_PERMS+=	${EGDIR}/nats-server.conf \
			${PKG_SYSCONFDIR}/nats-server.conf \
			${NATS_USER} ${NATS_GROUP} 0600

INSTALLATION_DIRS=	bin ${EGDIR}

OWN_DIRS_PERMS+=	${NATS_HOMEDIR} ${NATS_USER} ${NATS_GROUP} 0700
MAKE_DIRS_PERMS+=	${NATS_LOGDIR} ${NATS_USER} ${NATS_GROUP} 0700

.include "../../lang/go/go-module.mk"

post-install:
	${ECHO} "# Example config, see https://docs.nats.io/nats-server/configuration" > \
		${DESTDIR}/${EGDIR}/nats-server.conf

.include "../../mk/bsd.pkg.mk"

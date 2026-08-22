# $NetBSD: Makefile,v 1.17 2026/08/22 15:19:14 bsiegert Exp $

DISTNAME=	lima-2.1.1
PKGREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=lima-vm/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/lima-vm/lima
COMMENT=	Linux virtual machines for running containerd
LICENSE=	apache-2.0

USE_TOOLS+=	gmake

BUILD_DEFS+=	VARBASE

OWN_DIRS_PERMS+=	${VARBASE}/db/lima ${LIMA_USER} ${LIMA_GROUP} 0750

LIMA_USER?=	lima
LIMA_GROUP?=	lima

PKG_GROUPS_VARS+=	LIMA_GROUP
PKG_USERS_VARS+=	LIMA_USER

PKG_GROUPS=	${LIMA_GROUP}
PKG_USERS=	${LIMA_USER}:${LIMA_GROUP}

PKG_SHELL.${LIMA_USER}=	${SH}
PKG_HOME.${LIMA_USER}=	${VARBASE}/db/lima

FILES_SUBST+=	LIMA_USER=${LIMA_USER}
FILES_SUBST+=	LIMA_GROUP=${LIMA_GROUP}
FILES_SUBST+=	LIMA_USER_HOME=${VARBASE}/db/lima

RCD_SCRIPTS+=	lima

DEPENDS+=	qemu-[0-9]*:../../emulators/qemu

# Avoid to invoke/use git
MAKE_FLAGS+=	VERSION=${GITHUB_TAG}

.include "../../lang/go/go-vars.mk"
.include "../../mk/bsd.prefs.mk"

do-build:
	cd ${WRKSRC} && \
	${RUN} ${_ULIMIT_CMD} \
	${PKGSRC_SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${BUILD_MAKE_FLAGS} \
			${BUILD_TARGET}

INSTALLATION_DIRS+=	${PKGMANDIR}/man1 share/doc

do-install:
	${RUN} cd ${WRKSRC}/_output && ${PAX} -rw bin ${DESTDIR}${PREFIX}
	${RUN} cd ${WRKSRC}/_output/share/man && ${PAX} -rw man1 ${DESTDIR}${PREFIX}/${PKGMANDIR}
	${RUN} cd ${WRKSRC}/_output/share/doc && ${PAX} -rw lima ${DESTDIR}${PREFIX}/share/doc
	${RUN} cd ${WRKSRC}/_output/share && ${PAX} -rw lima ${DESTDIR}${PREFIX}/share

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"

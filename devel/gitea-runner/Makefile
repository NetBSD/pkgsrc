# $NetBSD: Makefile,v 1.2 2026/08/31 19:18:49 bsiegert Exp $

DISTNAME=	v${PKGVERSION_NOREV}
PKGNAME=	gitea-runner-3.3.1
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://gitea.com/gitea/runner/archive/
DIST_SUBDIR=	runner

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitea.com/gitea/runner/
COMMENT=	Runner for Gitea based on act
LICENSE=	mit

GO_VERSION_REQD=	127

WRKSRC=		${WRKDIR}/${DIST_SUBDIR}

BUILD_DEFS+=	VARBASE GITEA_RUNNER_USER GITEA_RUNNER_GROUP

EGDIR=		${PREFIX}/share/examples/gitea-runner

OWN_DIRS_PERMS+=	${VARBASE}/db/gitea-runner ${GITEA_RUNNER_USER} ${GITEA_RUNNER_GROUP} 0700
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR} ${GITEA_RUNNER_USER} ${GITEA_RUNNER_GROUP} 0755

GITEA_RUNNER_USER?=	runner
GITEA_RUNNER_GROUP?=	runner

PKG_GROUPS_VARS+=	GITEA_RUNNER_GROUP
PKG_USERS_VARS+=	GITEA_RUNNER_USER

PKG_SYSCONFSUBDIR=	gitea-runner

INSTALLATION_DIRS+=	share/examples/gitea-runner

PKG_SHELL.${GITEA_RUNNER_USER}=	${SH}
PKG_HOME.${GITEA_RUNNER_USER}=	${VARBASE}/db/gitea-runner

SUBST_CLASSES+=		fix-var
SUBST_STAGE.fix-var=	pre-configure
SUBST_MESSAGE.fix-var=	Replace some vars
SUBST_FILES.fix-var=	${WRKDIR}/config.yaml
SUBST_VARS.fix-var=	VARBASE

CONF_FILES_PERMS+=	${EGDIR}/config.yaml ${PKG_SYSCONFDIR}/config.yaml \
			${GITEA_RUNNER_USER} ${GITEA_RUNNER_GROUP} 0600

FILES_SUBST+=		GITEA_RUNNER_USER=${GITEA_RUNNER_USER}
FILES_SUBST+=		GITEA_RUNNER_GROUP=${GITEA_RUNNER_GROUP}

RCD_SCRIPTS+=		gitea-runner

pre-patch:
	${CP} ${FILESDIR}/config.yaml ${WRKDIR}/

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} runner gitea-runner
	${INSTALL_DATA} ${WRKDIR}/config.yaml ${DESTDIR}${EGDIR}

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"

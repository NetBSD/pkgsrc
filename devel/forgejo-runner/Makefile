# $NetBSD: Makefile,v 1.1 2026/10/23 16:00:58 khorben Exp $

DISTNAME=	v${PKGVERSION_NOREV}
PKGNAME=	forgejo-runner-13.2.0
CATEGORIES=	devel
MASTER_SITES=	https://code.forgejo.org/forgejo/runner/archive/
DIST_SUBDIR=	runner

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://forgejo.com/forgejo/runner/
COMMENT=	Runner for forgejo
LICENSE=	mit

GO_VERSION_REQD=	126

WRKSRC=		${WRKDIR}/${DIST_SUBDIR}

DEPENDS+=	git-base-[0-9]*:../../devel/git-base
DEPENDS+=	nodejs-[0-9]*:../../lang/nodejs

BUILD_DEFS+=	VARBASE FORGEJO_RUNNER_USER FORGEJO_RUNNER_GROUP

EGDIR=		${PREFIX}/share/examples/forgejo-runner

OWN_DIRS_PERMS+=	${VARBASE}/db/forgejo-runner ${FORGEJO_RUNNER_USER} ${FORGEJO_RUNNER_GROUP} 0700
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR} ${FORGEJO_RUNNER_USER} ${FORGEJO_RUNNER_GROUP} 0755

FORGEJO_RUNNER_USER?=	runner
FORGEJO_RUNNER_GROUP?=	runner

PKG_GROUPS_VARS+=	FORGEJO_RUNNER_GROUP
PKG_USERS_VARS+=	FORGEJO_RUNNER_USER

PKG_SYSCONFSUBDIR=	forgejo-runner

INSTALLATION_DIRS+=	share/examples/forgejo-runner

PKG_SHELL.${FORGEJO_RUNNER_USER}=	${SH}
PKG_HOME.${FORGEJO_RUNNER_USER}=	${VARBASE}/db/forgejo-runner

SUBST_CLASSES+=		fix-var
SUBST_STAGE.fix-var=	pre-configure
SUBST_MESSAGE.fix-var=	Replace some vars
SUBST_FILES.fix-var=	${WRKDIR}/config.yaml
SUBST_VARS.fix-var=	VARBASE

CONF_FILES_PERMS+=	${EGDIR}/config.yaml ${PKG_SYSCONFDIR}/config.yaml \
			${FORGEJO_RUNNER_USER} ${FORGEJO_RUNNER_GROUP} 0600

FILES_SUBST+=		FORGEJO_RUNNER_USER=${FORGEJO_RUNNER_USER}
FILES_SUBST+=		FORGEJO_RUNNER_GROUP=${FORGEJO_RUNNER_GROUP}
FILES_SUBST+=		FORGEJO_RUNNER_USER_HOME=${VARBASE}/db/forgejo-runner

RCD_SCRIPTS+=		forgejo-runner

pre-patch:
	${CP} ${FILESDIR}/config.yaml ${WRKDIR}/

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} runner forgejo-runner
	${INSTALL_DATA} ${WRKDIR}/config.yaml ${DESTDIR}${EGDIR}

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.28 2026/08/22 15:18:56 bsiegert Exp $

DISTNAME=	mimir-3.2.0
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=grafana/}
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/grafana/mimir/
COMMENT=	Horizontally scalable long-term storage for Prometheus
LICENSE=	gnu-agpl-v3

MAKE_ENV+=	CGO_ENABLED=0

CHECK_PORTABILITY_SKIP+=	docs/make-docs
CHECK_PORTABILITY_SKIP+=	vendor/cloud.google.com/go/internal/gen_info.sh

.include "go-modules.mk"

MIMIR_VERSION=	github.com/grafana/mimir/pkg/util/version
GOFLAGS=	-ldflags "-X ${MIMIR_VERSION}.Branch=${PKGVERSION_NOREV} -X ${MIMIR_VERSION}.Revision=${PKGREVISION} -X ${MIMIR_VERSION}.Version=${PKGVERSION_NOREV} -extldflags \"-static\" -s -w" -tags netgo,stringlabels

GO_BUILD_PATTERN=			\
	./cmd/mimirtool			\
	./cmd/mimir			\
	./cmd/metaconvert		\
	./cmd/query-tee

EXAMPLE_DIR=	share/examples/mimir

BUILD_DEFS+=	VARBASE PKG_SYSCONFDIR
DATADIR=	${VARBASE}/lib/mimir
LOGDIR=		${VARBASE}/log/mimir

BUILD_DEFS+=	MIMIR_USER MIMIR_GROUP
FILES_SUBST+=	MIMIR_USER=${MIMIR_USER:Q}
FILES_SUBST+=	MIMIR_GROUP=${MIMIR_GROUP:Q}
FILES_SUBST+=	DATADIR=${DATADIR:Q}
FILES_SUBST+=	LOGDIR=${LOGDIR:Q}

MIMIR_USER?=		mimir
MIMIR_GROUP?=		mimir
OWN_DIRS_PERMS+=	${DATADIR} ${MIMIR_USER} ${MIMIR_GROUP} 0700
OWN_DIRS_PERMS+=	${LOGDIR} ${MIMIR_USER} ${MIMIR_GROUP} 0700
PKG_USERS_VARS+=	MIMIR_USER
PKG_GROUPS_VARS+=	MIMIR_GROUP
PKG_GROUPS=		${MIMIR_GROUP}
PKG_USERS=		${MIMIR_USER}:${MIMIR_GROUP}
RCD_SCRIPTS=		mimir

INSTALLATION_DIRS+=	bin ${EXAMPLE_DIR}

CONF_FILES+=	${EXAMPLE_DIR}/mimir.yaml ${PKG_SYSCONFDIR}/mimir.yaml

post-install:
	${INSTALL_DATA} ${FILESDIR}/mimir.yaml		\
		${DESTDIR}${PREFIX}/${EXAMPLE_DIR}

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"

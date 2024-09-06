# $NetBSD: Makefile,v 1.5 2024/09/06 18:48:42 bsiegert Exp $

GITHUB_PROJECT=	mimir
DISTNAME=	mimir-2.13.0
PKGREVISION=	3
GITHUB_TAG=	${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=grafana/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/grafana/mimir/
COMMENT=	Horizontally scalable long-term storage for Prometheus
LICENSE=	gnu-agpl-v3

MAKE_ENV+=	CGO_ENABLED=0

CHECK_PORTABILITY_SKIP+=	docs/make-docs

.include "go-modules.mk"

MIMIR_VERSION=	github.com/grafana/mimir/pkg/util/version
GO_FLAGS=	-ldflags "-X ${MIMIR_VERSION}.Branch=${PKGVERSION_NOREV} -X ${MIMIR_VERSION}.Revision=${PKGREVISION} -X ${MIMIR_VERSION}.Version=${PKGVERSION_NOREV} -extldflags \"-static\" -s -w" -tags netgo,stringlabels

MIMIR_BINARIES=				\
	./cmd/mimirtool			\
	./cmd/mimir			\
	./cmd/query-tee			\
	./cmd/metaconvert		\
	./cmd/mimir-continuous-test	\
	./tools/markblocks

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

do-build:
.for b in ${MIMIR_BINARIES}
	@${ECHO_MSG} "Building ${b}"
	${RUN} cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GO} build ${GO_FLAGS} ${b}
.endfor

do-install:
.for b in ${MIMIR_BINARIES:C,.*/,,}
	${INSTALL_PROGRAM} ${WRKSRC}/${b} ${DESTDIR}${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${FILESDIR}/mimir.yaml		\
		${DESTDIR}${PREFIX}/${EXAMPLE_DIR}

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"

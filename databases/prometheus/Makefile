# $NetBSD: Makefile,v 1.133 2026/09/26 10:58:29 tnn Exp $

# Note that this package intends to track the Prometheus LTS version.
# See: https://prometheus.io/docs/introduction/release-cycle/
DISTNAME=		prometheus-3.13.3
MASTER_SITES=		${MASTER_SITE_GITHUB:=prometheus/}
CATEGORIES=		databases
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://prometheus.io/
COMMENT=	The Prometheus monitoring system and time series database
LICENSE=	apache-2.0

FE_DISTNAME=			prometheus-web-ui-3.13.3.tar.gz
SITES.${FE_DISTNAME}=		https://github.com/prometheus/prometheus/releases/download/v${PKGVERSION_NOREV}/
EXTRACT_DIR.${FE_DISTNAME}=	${WRKSRC}/web/ui
DISTFILES=			${DEFAULT_DISTFILES} ${FE_DISTNAME}
EXTRACT_ONLY=			${DEFAULT_DISTFILES} ${FE_DISTNAME}

USE_TOOLS+=		bash gzip

MAKE_ENV+=		GOWORK=off
MAKE_ENV+=		PREBUILT_ASSETS_STATIC_DIR=web/ui/static

EXAMPLE_DIR=		share/examples/prometheus
DATADIR=		${VARBASE}/lib/prometheus
LOGDIR=			${VARBASE}/lib/prometheus

BUILD_DEFS+=		VARBASE PROMETHEUS_USER PROMETHEUS_GROUP
FILES_SUBST+=		PROMETHEUS_USER=${PROMETHEUS_USER:Q}
FILES_SUBST+=		PROMETHEUS_GROUP=${PROMETHEUS_GROUP:Q}
FILES_SUBST+=		DATADIR=${DATADIR:Q}
FILES_SUBST+=		LOGDIR=${LOGDIR:Q}

OWN_DIRS_PERMS+=	${DATADIR} ${PROMETHEUS_USER} ${PROMETHEUS_GROUP} 0700
OWN_DIRS_PERMS+=	${LOGDIR} ${PROMETHEUS_USER} ${PROMETHEUS_GROUP} 0700
PKG_USERS_VARS+=	PROMETHEUS_USER
PKG_GROUPS_VARS+=	PROMETHEUS_GROUP
PKG_GROUPS=		${PROMETHEUS_GROUP}
PKG_USERS=		${PROMETHEUS_USER}:${PROMETHEUS_GROUP}
RCD_SCRIPTS=		prometheus

INSTALLATION_DIRS+=	${EXAMPLE_DIR}
CONF_FILES+=		${EXAMPLE_DIR}/prometheus.yml ${PKG_SYSCONFDIR}/prometheus.yml

GOFLAGS+=	-ldflags " \
		-X github.com/prometheus/common/version.Version=${PKGVERSION_NOREV} \
		-X github.com/prometheus/common/version.Revision=${PKGVERSION} \
		-X github.com/prometheus/common/version.Branch=pkgsrc \
		-X github.com/prometheus/common/version.BuildUser=pkgsrc@localhost \
		-X github.com/prometheus/common/version.BuildDate=${:!date +%Y%m%d-%H:%M:%S!}" \
		-tags netgo,builtinassets

GO_BUILD_PATTERN+=	./cmd/prometheus
GO_BUILD_PATTERN+=	./cmd/promtool

pre-build:
	${RUN} cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ./scripts/compress_assets.sh

post-install:
	${INSTALL_DATA} ${WRKSRC}/documentation/examples/prometheus.yml \
		${DESTDIR}${PREFIX}/${EXAMPLE_DIR}/.

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"

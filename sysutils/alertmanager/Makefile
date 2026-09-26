# $NetBSD: Makefile,v 1.1 2026/09/26 10:42:59 tnn Exp $

DISTNAME=	alertmanager-0.34.1
MASTER_SITES=	${MASTER_SITE_GITHUB:=prometheus/}
CATEGORIES=	sysutils
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://prometheus.io/
COMMENT=	Prometheus Alertmanager
LICENSE=	apache-2.0

DISTFILES=	${DEFAULT_DISTFILES}

FE_DISTNAME=			alertmanager-web-ui-0.34.1.tar.gz
DISTFILES+=			${FE_DISTNAME}
SITES.${FE_DISTNAME}=		https://github.com/prometheus/alertmanager/releases/download/v${PKGVERSION_NOREV}/
EXTRACT_DIR.${FE_DISTNAME}=	${WRKSRC}/ui/app
EXTRACT_ONLY=			${DEFAULT_DISTFILES} ${FE_DISTNAME}

EXAMPLE_DIR=		share/examples/alertmanager
DATADIR=		${VARBASE}/lib/alertmanager
LOGDIR=			${VARBASE}/log/alertmanager

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
RCD_SCRIPTS=		alertmanager

INSTALLATION_DIRS+=	${EXAMPLE_DIR}
CONF_FILES_PERMS+=	${EXAMPLE_DIR}/simple.yml ${PKG_SYSCONFDIR}/alertmanager.yml ${PROMETHEUS_USER} ${PROMETHEUS_GROUP} 0640

GOFLAGS+=		-ldflags " \
			-X github.com/prometheus/common/version.Version=${PKGVERSION_NOREV} \
			-X github.com/prometheus/common/version.Revision=${PKGVERSION} \
			-X github.com/prometheus/common/version.Branch=pkgsrc \
			-X github.com/prometheus/common/version.BuildUser=pkgsrc@localhost \
			-X github.com/prometheus/common/version.BuildDate=${:!date +%Y%m%d-%H:%M:%S!}" \
			-tags netgo

GO_BUILD_PATTERN+=	./cmd/alertmanager
GO_BUILD_PATTERN+=	./cmd/amtool

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/examples/simple.yml \
	  ${DESTDIR}${PREFIX}/${EXAMPLE_DIR}/.

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.6 2019/10/18 14:58:43 bsiegert Exp $

DISTNAME=	influxdb-1.7.6
MASTER_SITES=	${MASTER_SITE_GITHUB:=influxdata/}
PKGREVISION=	5
CATEGORIES=	databases
GITHUB_PROJECT=	influxdb
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/influxdata/influxdb
COMMENT=	Scalable datastore for metrics, events, and real-time analytics
LICENSE=	mit

BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc
BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

USE_TOOLS+=	gmake

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/influxdata/influxdb

PKG_SYSCONFSUBDIR=	influxdb

DATADIR=	${VARBASE}/lib/influxdb
LOGDIR=		${VARBASE}/log/influxdb

BUILD_DEFS+=		INFLUXDB_USER INFLUXDB_GROUP VARBASE
FILES_SUBST+=		INFLUXDB_USER=${INFLUXDB_USER:Q}
FILES_SUBST+=		INFLUXDB_GROUP=${INFLUXDB_GROUP:Q}
FILES_SUBST+=		DATADIR=${DATADIR:Q}
FILES_SUBST+=		LOGDIR=${LOGDIR:Q}

INFLUXDB_USER?=		influxdb
INFLUXDB_GROUP?=	influxdb
OWN_DIRS_PERMS+=	${DATADIR} ${INFLUXDB_USER} ${INFLUXDB_GROUP} 0700
OWN_DIRS_PERMS+=	${LOGDIR} ${INFLUXDB_USER} ${INFLUXDB_GROUP} 0700
PKG_USERS_VARS+=	INFLUXDB_USER
PKG_GROUPS_VARS+=	INFLUXDB_GROUP
PKG_GROUPS=		${INFLUXDB_GROUP}
PKG_USERS=		${INFLUXDB_USER}:${INFLUXDB_GROUP}
RCD_SCRIPTS=		influxdb

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/doc/influxdb share/examples/influxdb

DOC_FILES+=	LICENSE DEPENDENCIES.md QUERIES.md README.md CHANGELOG.md
BIN_FILES+=	influx influx_inspect influx_stress influx_tsm influxd
BIN_FILES+=	stress_test_server test_client
CONF_FILES+=	${PREFIX}/share/examples/${PKGBASE}/config.sample.toml \
		${PKG_SYSCONFDIR}/config.toml

.include "go-deps.mk"

INFLUX_GO_FLAGS=	-s
INFLUX_GO_FLAGS+=	-X main.version=${PKGVERSION_NOREV}
INFLUX_GO_FLAGS+=	-X main.commit=${GITHUB_TAG}
INFLUX_GO_FLAGS+=	-X main.buildstamp=pkgsrc

do-build:
	${RUN} ${PKGSRC_SETENV} ${MAKE_ENV} \
		${GO} build -ldflags "${INFLUX_GO_FLAGS}" ${GO_BUILD_PATTERN}
	${RUN} ${PKGSRC_SETENV} ${MAKE_ENV} \
		${GO} install -ldflags "${INFLUX_GO_FLAGS}" ${GO_BUILD_PATTERN}
	${RUN} cd ${WRKSRC}/man && ${PKGSRC_SETENV} ${MAKE_ENV} ${GMAKE}
	${RUN} ${SED} \
	    -e 's,/var,${VARBASE},g' \
	    -e 's,^# reporting.*,reporting-disabled = true,g' \
		${WRKSRC}/etc/config.sample.toml >${WRKDIR}/.config.toml

do-install:
	for manpage in ${WRKSRC}/man/*.1; do \
		${INSTALL_MAN} $$manpage ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1; \
	done
.for x in ${BIN_FILES}
	${INSTALL_PROGRAM} ${WRKDIR}/bin/${x} \
		${DESTDIR}${PREFIX}/bin/${x}
.endfor
.for x in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${x} \
		${DESTDIR}${PREFIX}/share/doc/influxdb/${x}
.endfor
	${INSTALL_DATA} ${WRKSRC}/etc/config.sample.toml ${DESTDIR}${PREFIX}/share/examples/${PKGBASE}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"

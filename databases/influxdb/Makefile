# $NetBSD: Makefile,v 1.30 2022/01/09 20:10:30 bsiegert Exp $

DISTNAME=	influxdb-1.8.4
MASTER_SITES=	${MASTER_SITE_GITHUB:=influxdata/}
PKGREVISION=	8
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
PKG_SYSCONFSUBDIR=	influxdb
RCD_SCRIPTS=		influxdb

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/doc/influxdb share/examples/influxdb

DOC_FILES+=	LICENSE DEPENDENCIES.md QUERIES.md README.md CHANGELOG.md
BIN_FILES+=	influx influx_inspect influx_stress influx_tools influx_tsm
BIN_FILES+=	influxd
CONF_FILES+=	${PREFIX}/share/examples/${PKGBASE}/config.sample.toml \
		${PKG_SYSCONFDIR}/config.toml

.include "go-modules.mk"

INFLUX_GO_FLAGS=	-s
INFLUX_GO_FLAGS+=	-X main.version=${PKGVERSION_NOREV}
INFLUX_GO_FLAGS+=	-X main.commit=${GITHUB_TAG}
INFLUX_GO_FLAGS+=	-X main.branch=${PKGVERSION_NOREV}
INFLUX_GO_FLAGS+=	-X main.buildstamp=pkgsrc

do-build:
.for cmd in ${BIN_FILES}
	${RUN} cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} \
		${GO} build -ldflags "${INFLUX_GO_FLAGS}" ./cmd/${cmd}
.endfor
	${RUN} cd ${WRKSRC}/man && ${PKGSRC_SETENV} ${MAKE_ENV} ${GMAKE}
	${RUN} ${SED} \
	    -e 's,/var,${VARBASE},g' \
	    -e 's,^# reporting.*,reporting-disabled = true,g' \
		${WRKSRC}/etc/config.sample.toml >${WRKDIR}/.config.toml

do-install:
.for cmd in ${BIN_FILES}
	${INSTALL_PROGRAM} ${WRKSRC}/${cmd} ${DESTDIR}${PREFIX}/bin/${cmd}
.endfor
	for manpage in ${WRKSRC}/man/*.1; do \
		${INSTALL_MAN} $$manpage ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1; \
	done
.for f in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} \
		${DESTDIR}${PREFIX}/share/doc/influxdb/${f}
.endfor
	${INSTALL_DATA} ${WRKSRC}/etc/config.sample.toml ${DESTDIR}${PREFIX}/share/examples/${PKGBASE}

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"

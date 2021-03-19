# $NetBSD: Makefile,v 1.47 2021/03/19 17:36:47 bsiegert Exp $

# Important: UI has to be manually built. See instructions below.

DISTNAME=	prometheus-2.24.1
PKGREVISION=	2
MASTER_SITES=	${MASTER_SITE_GITHUB:=prometheus/}
CATEGORIES=	databases
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://prometheus.io/
COMMENT=	The Prometheus monitoring system and time series database
LICENSE=	apache-2.0

# To generate UI distfile, install devel/yarn, and:
# tar zxf ${DISTNAME}${EXTRACT_SUFX}
# cd ${DISTNAME}/web/ui/react-app
# yarn --frozen-lockfile
# env PUBLIC_URL=. yarn build
# chmod -x build/favicon.ico build/manifest.json
# mv build ../static/react
# cd ../../../..
# tar zcf ${DISTNAME}-react-ui.tar.gz ${DISTNAME}/web/ui/static/react
REACT_UI_DIST=		${DISTNAME}-react-ui.tar.gz
SITES.${REACT_UI_DIST}=	${MASTER_SITE_LOCAL}
DISTFILES=		${DEFAULT_DISTFILES} ${REACT_UI_DIST}

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/prometheus/prometheus

GO_BUILD_DATE_cmd=	${DATE} "+%Y-%m-%d"
GO_XFLAG_PREFIX=	-X ${GO_SRCPATH}/vendor/${GO_SRCPATH:H}/common/version

GO_LDFLAGS=	-s
GO_LDFLAGS+=	${GO_XFLAG_PREFIX}.Branch=release-${PKGVERSION_NOREV:R}
GO_LDFLAGS+=	${GO_XFLAG_PREFIX}.BuildDate=${GO_BUILD_DATE_cmd:sh}
GO_LDFLAGS+=	${GO_XFLAG_PREFIX}.BuildUser=pkgsrc
GO_LDFLAGS+=	${GO_XFLAG_PREFIX}.Revision=${GITHUB_TAG}
GO_LDFLAGS+=	${GO_XFLAG_PREFIX}.Version=${PKGVERSION_NOREV}

PKG_SYSCONFSUBDIR=	prometheus

USE_TOOLS+=	pax
BUILD_DEFS+=	VARBASE PKG_SYSCONFDIR

SUBST_CLASSES+=		paths
SUBST_FILES.paths+=	cmd/prometheus/main.go
SUBST_STAGE.paths=	post-configure
SUBST_VARS.paths=	PKG_SYSCONFDIR VARBASE

SUBST_CLASSES+=		webui
SUBST_FILES.webui=	web/ui/ui.go
SUBST_STAGE.webui=	post-configure
SUBST_VARS.webui=	WEBUI_DIR

MAKE_DIRS+=	${PKG_SYSCONFDIR}/consoles ${PKG_SYSCONFDIR}/console_libraries
EXAMPLE_DIR=	share/examples/prometheus
EXAMPLE_FILES=	prometheus.yml
EXAMPLE_FILES+=	consoles/index.html.example consoles/node-cpu.html \
		consoles/node-disk.html consoles/node-overview.html \
		consoles/node.html consoles/prometheus-overview.html \
		consoles/prometheus.html
EXAMPLE_FILES+=	console_libraries/menu.lib console_libraries/prom.lib
WEBUI_DIR=	${PREFIX}/share/prometheus

INSTALLATION_DIRS+=	bin ${EXAMPLE_DIR} ${WEBUI_DIR}

.for f in ${EXAMPLE_FILES}
CONF_FILES+=	${EXAMPLE_DIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

do-build:
	${RUN} ${_ULIMIT_CMD} ${PKGSRC_SETENV} ${MAKE_ENV} \
		${GO} install -v -ldflags ${GO_LDFLAGS:Q} ${GO_BUILD_PATTERN}

do-install:
	${INSTALL_DATA} ${WRKSRC}/documentation/examples/prometheus.yml \
		${DESTDIR}${PREFIX}/${EXAMPLE_DIR}
.for f in prometheus promtool
	${INSTALL_PROGRAM} ${WRKDIR}/bin/${f} ${DESTDIR}${PREFIX}/bin
.endfor
.for f in consoles console_libraries
	cd ${WRKSRC} && ${PAX} -rw ${f} ${DESTDIR}${PREFIX}/${EXAMPLE_DIR}
.endfor
.for f in static templates
	cd ${WRKSRC}/web/ui && ${PAX} -rw ${f} ${DESTDIR}${WEBUI_DIR}
	${CHMOD} -R g-w ${DESTDIR}${WEBUI_DIR}/${f}
.endfor

post-install:
.for f in ${EXAMPLE_FILES}
	${CHMOD} ${NONBINMODE} ${DESTDIR}${PREFIX}/${EXAMPLE_DIR}/${f}
.endfor

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"

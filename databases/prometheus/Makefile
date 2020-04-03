# $NetBSD: Makefile,v 1.19 2020/04/03 16:39:50 adam Exp $

DISTNAME=	prometheus-2.17.1
MASTER_SITES=	${MASTER_SITE_GITHUB:=prometheus/}
CATEGORIES=	databases
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://prometheus.io/
COMMENT=	The Prometheus monitoring system and time series database
LICENSE=	apache-2.0

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/prometheus/prometheus

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

INSTALLATION_DIRS+=	${PREFIX}/${EXAMPLE_DIR} ${WEBUI_DIR}

.for f in ${EXAMPLE_FILES}
CONF_FILES+=	${EXAMPLE_DIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

do-install:
	${INSTALL_DATA} ${WRKSRC}/documentation/examples/prometheus.yml \
		${DESTDIR}${PREFIX}/${EXAMPLE_DIR}
	cd ${WRKDIR} && ${PAX} -rw bin ${DESTDIR}${PREFIX}
.for f in consoles console_libraries
	cd ${WRKSRC} && ${PAX} -rw ${f} ${DESTDIR}${PREFIX}/${EXAMPLE_DIR}
.endfor
.for f in static templates
	cd ${WRKSRC}/web/ui && ${PAX} -rw ${f} ${DESTDIR}${WEBUI_DIR}
.endfor

post-install:
.for f in ${EXAMPLE_FILES}
	${CHMOD} ${NONBINMODE} ${DESTDIR}${PREFIX}/${EXAMPLE_DIR}/${f}
.endfor

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"

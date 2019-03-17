# $NetBSD: Makefile,v 1.1 2019/03/17 12:55:13 tm Exp $

DISTNAME=	prometheus-2.8.0
MASTER_SITES=	${MASTER_SITE_GITHUB:=prometheus/}
CATEGORIES=	databases
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/prometheus/prometheus
COMMENT=	The Prometheus monitoring system and time series database
LICENSE=	apache-2.0

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/prometheus/prometheus

PKG_SYSCONFSUBDIR=	prometheus

USE_TOOLS+=	pax
BUILD_DEFS+=	VARBASE PKG_SYSCONFDIR

SUBST_CLASSES+=		paths
SUBST_FILES.paths+=	cmd/prometheus/main.go
SUBST_SED.paths+=	-e "s|@VARBASE@|${VARBASE}|g"
SUBST_SED.paths+=	-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"
SUBST_STAGE.paths=	post-configure

MAKE_DIRS+=		${PKG_SYSCONFDIR}/consoles ${PKG_SYSCONFDIR}/console_libraries
EXAMPLE_DIR=		share/examples/prometheus
EXAMPLE_FILES=		prometheus.yml
EXAMPLE_FILES+=		consoles/index.html.example consoles/node-cpu.html \
			consoles/node-disk.html consoles/node-overview.html \
			consoles/node.html consoles/prometheus-overview.html \
			consoles/prometheus.html
EXAMPLE_FILES+=		console_libraries/menu.lib console_libraries/prom.lib
INSTALLATION_DIRS+=	${PREFIX}/${EXAMPLE_DIR}

.for f in ${EXAMPLE_FILES}
CONF_FILES+=	${EXAMPLE_DIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

do-install:
	${INSTALL_DATA} ${WRKSRC}/documentation/examples/prometheus.yml ${DESTDIR}${PREFIX}/${EXAMPLE_DIR}
	${RUN} cd ${WRKDIR} && ${PAX} -rw bin ${DESTDIR}${PREFIX}
	${RUN} cd ${WRKSRC} && \
		${PAX} -rw consoles ${DESTDIR}${PREFIX}/${EXAMPLE_DIR} && \
		${PAX} -rw console_libraries ${DESTDIR}${PREFIX}/${EXAMPLE_DIR}

post-install:
.for f in ${EXAMPLE_FILES}
	${CHMOD} ${NONBINMODE} ${DESTDIR}${PREFIX}/${EXAMPLE_DIR}/${f}
.endfor

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"

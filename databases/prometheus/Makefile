# $NetBSD: Makefile,v 1.6 2019/08/14 15:45:33 bsiegert Exp $

DISTNAME=	prometheus-2.10.0
MASTER_SITES=	${MASTER_SITE_GITHUB:=prometheus/}
PKGREVISION=	1
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
	cd ${WRKDIR} && ${PAX} -rw bin ${DESTDIR}${PREFIX}
	cd ${WRKSRC} && \
		${PAX} -rw consoles ${DESTDIR}${PREFIX}/${EXAMPLE_DIR} && \
		${PAX} -rw console_libraries ${DESTDIR}${PREFIX}/${EXAMPLE_DIR}

post-install:
.for f in ${EXAMPLE_FILES}
	${CHMOD} ${NONBINMODE} ${DESTDIR}${PREFIX}/${EXAMPLE_DIR}/${f}
.endfor

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"

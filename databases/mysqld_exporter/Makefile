# $NetBSD: Makefile,v 1.18 2022/08/12 20:38:06 bsiegert Exp $

DISTNAME=	mysqld_exporter-0.12.1
MASTER_SITES=	${MASTER_SITE_GITHUB:=prometheus/}
PKGREVISION=	17
CATEGORIES=	databases
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@pkgsrc.org
HOMEPAGE=	https://github.com/prometheus/mysqld_exporter
COMMENT=	MySQL metric exporter for Prometheus
LICENSE=	apache-2.0

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/prometheus/mysqld_exporter

SMF_METHODS=	${PKGBASE}

EGDIR=			share/examples/${PKGBASE}
PKG_SYSCONFSUBDIR=	${PKGBASE}

INSTALLATION_DIRS=	bin ${EGDIR}

CONF_FILES_PERMS+=	${EGDIR}/env.conf ${PKG_SYSCONFDIR}/env.conf \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 600

post-build:
	${SED} -e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g' \
	    ${FILESDIR}/env.conf >${WRKDIR}/.env.conf

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/mysqld_exporter \
	    ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/.env.conf \
	    ${DESTDIR}${PREFIX}/share/examples/${PKGBASE}/env.conf

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"

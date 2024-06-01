# $NetBSD: Makefile,v 1.41 2024/06/01 14:02:49 bsiegert Exp $

DISTNAME=	mysqld_exporter-0.15.1
MASTER_SITES=	${MASTER_SITE_GITHUB:=prometheus/}
PKGREVISION=	4
CATEGORIES=	databases
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@pkgsrc.org
HOMEPAGE=	https://github.com/prometheus/mysqld_exporter
COMMENT=	MySQL metric exporter for Prometheus
LICENSE=	apache-2.0

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
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/mysqld_exporter \
	    ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/.env.conf \
	    ${DESTDIR}${PREFIX}/share/examples/${PKGBASE}/env.conf

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"

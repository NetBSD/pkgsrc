# $NetBSD: Makefile,v 1.28 2022/01/09 20:10:30 bsiegert Exp $

DISTNAME=	postgres_exporter-0.5.1
MASTER_SITES=	${MASTER_SITE_GITHUB:=wrouesnel/}
PKGREVISION=	25
CATEGORIES=	databases
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@pkgsrc.org
HOMEPAGE=	https://github.com/wrouesnel/postgres_exporter
COMMENT=	PostgresSQL metric exporter for Prometheus
LICENSE=	apache-2.0

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/wrouesnel/postgres_exporter

SMF_METHODS=	${PKGBASE}

EGDIR=			share/examples/${PKGBASE}
PKG_SYSCONFSUBDIR=	${PKGBASE}

INSTALLATION_DIRS+=	${EGDIR}

CONF_FILES_PERMS+=	${EGDIR}/queries.yaml ${PKG_SYSCONFDIR}/queries.yaml \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 644
CONF_FILES_PERMS+=	${EGDIR}/env.conf ${PKG_SYSCONFDIR}/env.conf \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 600

post-build:
	${SED} -e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g' ${FILESDIR}/env.conf \
	    >${WRKDIR}/.env.conf

post-install:
	${INSTALL_DATA} ${WRKSRC}/queries.yaml \
	    ${DESTDIR}${PREFIX}/share/examples/${PKGBASE}/queries.yaml
	${INSTALL_DATA} ${WRKDIR}/.env.conf \
	    ${DESTDIR}${PREFIX}/share/examples/${PKGBASE}/env.conf

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"

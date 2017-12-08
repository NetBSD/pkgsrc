# $NetBSD: Makefile,v 1.1 2017/12/08 15:27:46 jperkin Exp $

DISTNAME=	repmgr-4.0.1
PKGNAME=	postgresql${PGSQL_VERSION}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=2ndQuadrant/}
GITHUB_PROJECT=	repmgr
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/2ndQuadrant/repmgr/
COMMENT=	The Most Popular Replication Manager for PostgreSQL (Postgres)
LICENSE=	gnu-gpl-v3

DEPENDS+=	postgresql${PGSQL_VERSION}-server>=0:../../databases/postgresql${PGSQL_VERSION}-server

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

SMF_NAME=	postgresql-repmgr

BUILD_DEFS+=	PGUSER PGGROUP PGHOME
FILES_SUBST+=	PGUSER=${PGUSER} PGGROUP=${PGGROUP} PGHOME=${PGHOME}

DOCDIR=		share/doc/repmgr
EGDIR=		share/examples/repmgr
PKG_SYSCONFSUBDIR=	postgresql

INSTALLATION_DIRS+=	${DOCDIR} ${EGDIR}

CONF_FILES_PERMS+=	${EGDIR}/repmgr.conf.sample \
			${PKG_SYSCONFDIR}/repmgr.conf \
			${REAL_ROOT_USER} ${PGGROUP} 0640

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.md \
	    ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/repmgr.conf.sample \
	    ${DESTDIR}${PREFIX}/${EGDIR}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

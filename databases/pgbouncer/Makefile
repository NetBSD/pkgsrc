# $NetBSD: Makefile,v 1.8 2014/05/13 14:18:49 fhajny Exp $
#

DISTNAME=	pgbouncer-${VERSION}
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/3393/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc@NetBSD.org
HOMEPAGE=	http://wiki.postgresql.org/wiki/PgBouncer
COMMENT=	Lightweight connection pooler for PostgreSQL
LICENSE=	original-bsd

VERSION=	1.5.4
USE_LANGUAGES=	c
USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-libevent=${BUILDLINK_PREFIX.libevent}

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=		${EGDIR}/pgbouncer.ini ${PKG_SYSCONFDIR}/pgbouncer.ini \
			${EGDIR}/pgbouncer.userlist ${PKG_SYSCONFDIR}/pgbouncer.userlist

RCD_SCRIPTS+=		pgbouncer

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5 ${EGDIR}

.include "../../mk/bsd.prefs.mk"

PGUSER?=		pgsql
PGGROUP?=		pgsql
PKG_GROUPS=		${PGGROUP}
PKG_USERS=		${PGUSER}:${PGGROUP}
PKG_GECOS.${PGUSER}=	PostgreSQL database administrator
PKG_HOME.${PGUSER}=	${PGHOME}

BUILD_DEFS+=		PGUSER PGGROUP PGHOME VARBASE
FILES_SUBST+=		PGUSER=${PGUSER}
FILES_SUBST+=		PGGROUP=${PGGROUP}
FILES_SUBST+=		PGHOME=${PGHOME}

PGB_LOG_DIR?=		${VARBASE}/log/pgbouncer
PGB_RUN_DIR?=		${VARBASE}/run

OWN_DIRS_PERMS+=	${PGB_LOG_DIR} ${PGUSER} ${PGGROUP} 0755

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_MESSAGE.path=	Fixing default paths
SUBST_FILES.path=	etc/pgbouncer.ini
SUBST_SED.path=		-e 's|/var/log/pgbouncer|${PGB_LOG_DIR}|g'
SUBST_SED.path+=	-e 's|/var/run/pgbouncer|${PGB_RUN_DIR}|g'
SUBST_SED.path+=	-e 's|/etc/pgbouncer|${PKG_SYSCONFDIR}|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pgbouncer ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/doc/pgbouncer.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/pgbouncer.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/
	${INSTALL_DATA} ${WRKSRC}/etc/pgbouncer.ini ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/userlist.txt ${DESTDIR}${EGDIR}/pgbouncer.userlist

BUILDLINK_API_DEPENDS.libevent+= libevent>=2.0
.include "../../devel/libevent/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

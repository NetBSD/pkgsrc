# $NetBSD: Makefile,v 1.11 2016/03/15 11:29:35 fhajny Exp $
#

DISTNAME=	pgbouncer-1.7.2
CATEGORIES=	databases
MASTER_SITES=	http://pgbouncer.github.io/downloads/files/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc@NetBSD.org
HOMEPAGE=	http://pgbouncer.github.io/
COMMENT=	Lightweight connection pooler for PostgreSQL
LICENSE=	original-bsd

USE_LANGUAGES=	c
USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

PGB_USER?=		pgbounce
PGB_GROUP?=		pgbounce
PGB_LOG_DIR?=		${VARBASE}/log/pgbouncer
PGB_RUN_DIR?=		${VARBASE}/run

PKG_GROUPS=		${PGB_GROUP}
PKG_USERS=		${PGB_USER}:${PGB_GROUP}
PKG_GECOS.${PGB_USER}=	PgBouncer daemon user
PKG_HOME.${PGB_USER}=	${PGB_LOG_DIR}

BUILD_DEFS+=		PGB_USER PGB_GROUP VARBASE
FILES_SUBST+=		PGB_USER=${PGB_USER}
FILES_SUBST+=		PGB_GROUP=${PGB_GROUP}

OWN_DIRS_PERMS+=	${PGB_LOG_DIR} ${PGB_USER} ${PGB_GROUP} 0755

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=		${EGDIR}/pgbouncer.ini ${PKG_SYSCONFDIR}/pgbouncer.ini \
			${EGDIR}/userlist.txt ${PKG_SYSCONFDIR}/pgbouncer.userlist

RCD_SCRIPTS+=		pgbouncer

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_MESSAGE.path=	Fixing default paths
SUBST_FILES.path=	etc/pgbouncer.ini
SUBST_SED.path=		-e 's|/var/log/pgbouncer|${PGB_LOG_DIR}|g'
SUBST_SED.path+=	-e 's|/var/run/pgbouncer|${PGB_RUN_DIR}|g'
SUBST_SED.path+=	-e 's|/etc/pgbouncer|${PKG_SYSCONFDIR}|g'
SUBST_SED.path+=	-e 's|userlist.txt|pgbouncer.userlist|g'

CONFIGURE_ARGS+=	--with-cares=${BUILDLINK_PREFIX.libcares}
CONFIGURE_ARGS+=	--with-libevent=${BUILDLINK_PREFIX.libevent}

CPPFLAGS.SunOS+=	-D_STRUCTURED_PROC=1

# Avoid unwanted asciidoc/xmlto matches, get on without the html doc files.
# Bundled install-sh script unreliable. Install sample config files.
INSTALL_MAKE_FLAGS+=	ASCIIDOC=
INSTALL_MAKE_FLAGS+=	MKDIR_P=${INSTALL_DATA_DIR:Q}
INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5 ${EGDIR}

BUILDLINK_API_DEPENDS.libevent+= libevent>=2.0
.include "../../devel/libevent/buildlink3.mk"
.include "../../net/libcares/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

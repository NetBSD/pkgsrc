# $NetBSD: Makefile,v 1.19 2022/02/06 17:52:24 abs Exp $

PKGNAME=	${DISTNAME:S/-/-server-/}
PKGREVISION=	5
COMMENT=	MariaDB 10.4, a free MySQL compatible database (server)

CONFLICTS=	mysql-server-[0-9]*

.include "../../databases/mariadb104-client/Makefile.common"

BUILD_DEFS+=		VARBASE

.include "../../mk/bsd.fast.prefs.mk"

# mariabackup is not built on SunOS due to symbol resolution problems
# auth_pam is not built on SunOS due to lack of getgrouplist

PLIST_VARS+=		auth_pam mariabackup
.if ${OPSYS} != "SunOS"
PLIST.auth_pam=		yes
PLIST.mariabackup=	yes
.endif

MARIADB_USER?=		${MYSQL_USER:Umariadb}
MARIADB_GROUP?=		${MYSQL_GROUP:Umariadb}

PKG_USERS_VARS+=	MARIADB_USER
PKG_GROUPS_VARS+=	MARIADB_GROUP

PKG_GROUPS=		${MARIADB_GROUP}
PKG_USERS=		${MARIADB_USER}:${MARIADB_GROUP}

PKG_GECOS.${MARIADB_USER}=	MariaDB administrator
PKG_HOME.${MARIADB_USER}=	${MARIADB_DATADIR}
PKG_SHELL.${MARIADB_USER}=	${SH}

RCD_SCRIPTS=		mariadb
SMF_NAME=		mariadb
SMF_METHODS=		${RCD_SCRIPTS}

CMAKE_ARGS+=		-DCONNECT_WITH_MONGO=NO

FILES_SUBST+=		HOSTNAME_CMD=${HOSTNAME_CMD:Q}
FILES_SUBST+=		MARIADB_DATADIR=${MARIADB_DATADIR}
FILES_SUBST+=		MARIADB_USER=${MARIADB_USER} MARIADB_GROUP=${MARIADB_GROUP}
BUILD_DEFS+=		MARIADB_DATADIR

OWN_DIRS_PERMS+=	${MARIADB_DATADIR} ${MARIADB_USER} ${MARIADB_GROUP} 0700
OWN_DIRS_PERMS+=	${VARBASE}/run/mariadb ${MARIADB_USER} ${MARIADB_GROUP} 0700
OWN_DIRS_PERMS+=	${VARBASE}/log/mariadb ${MARIADB_USER} ${MARIADB_GROUP} 0700

USE_TOOLS=		bash:run perl:run
REPLACE_BASH+=		scripts/wsrep_sst_*.sh
REPLACE_BASH+=		scripts/mariadb-service-convert

post-install:
	${CHMOD} +x ${DESTDIR}${PREFIX}/bin/mysql_install_db

.include "options.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../databases/mariadb104-client/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

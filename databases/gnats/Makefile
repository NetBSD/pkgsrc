# $NetBSD: Makefile,v 1.47 2024/01/15 08:23:57 rillig Exp $

DISTNAME=	gnats-4.2.0
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GNU:=gnats/}
PKGREVISION=	5

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/gnats/
COMMENT=	GNATS bug tracking system
LICENSE=	gnu-gpl-v3

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gm4 gmake makeinfo bison
TEXINFO_REQD+=		4.6
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
MAKE_JOBS_SAFE=		no

BUILD_DEFS+=		VARBASE
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--enable-gnats-service=service-name=${GNATS_SERVICE}
CONFIGURE_ARGS+=	--enable-gnats-user=${GNATS_USER:Q}
CONFIGURE_ARGS+=	--enable-gnatsd-user-access-file=${GNATS_USER_FILE:Q}
CONFIGURE_ARGS+=	--enable-gnatsd-host-access-file=${GNATS_HOST_FILE:Q}
CONFIGURE_ARGS+=	--enable-gnats-dblist-file=${GNATS_DB_FILE:Q}
CONFIGURE_ARGS+=	--enable-gnats-default-db=${GNATS_DBHOME:Q}
CONFIGURE_ARGS+=	--with-lispdir=${PREFIX}/share/gnats

BUILDLINK_TRANSFORM+=	rm:-Werror

INFO_FILES=		yes

PKG_SYSCONFSUBDIR=	gnats

.include "../../mk/bsd.prefs.mk"

GNATS_USER?=	gnats
GNATS_GROUP?=	daemon
GNATS_SERVICE?=	support
GNATS_HOME?=	${VARBASE}/db/gnats
PKG_GROUPS=	${GNATS_GROUP}
PKG_USERS=	${GNATS_USER}:${GNATS_GROUP}

PKG_GROUPS_VARS+=	GNATS_GROUP
PKG_USERS_VARS+=	GNATS_USER

PKG_GECOS.${GNATS_USER}=	GNATS database owner
PKG_HOME.${GNATS_USER}=		${GNATS_HOME}
PKG_SHELL.${GNATS_USER}=	${SH}

GNATS_USER_FILE?=	${PKG_SYSCONFDIR}/gnatsd.user_access
GNATS_HOST_FILE?=	${PKG_SYSCONFDIR}/gnatsd.host_access
GNATS_DB_FILE?=		${PKG_SYSCONFDIR}/databases
GNATS_DBHOME?=		${GNATS_HOME}/gnatsdb

REQD_DIRS+=		${PREFIX}/share/gnats
REQD_DIRS+=		${PREFIX}/libexec/gnats
REQD_DIRS+=		${EGDIR}
OWN_DIRS_PERMS+=	${GNATS_HOME} ${GNATS_USER} ${GNATS_GROUP} 755

INSTALLATION_DIRS=	bin libexec/gnats ${PKGINFODIR} share
INSTALLATION_DIRS+=	share/examples share/examples/gnats
INSTALLATION_DIRS+=	share/gnats share/gnats/defaults
INSTALLATION_DIRS+=	${PKGMANDIR}/man1 ${PKGMANDIR}/man5
INSTALLATION_DIRS+=	${PKGMANDIR}/man7 ${PKGMANDIR}/man8

EGDIR=			${PREFIX}/share/examples/gnats
CONF_FILES_PERMS+=	${EGDIR}/gnatsd.user_access  ${GNATS_USER_FILE}	\
			${GNATS_USER} ${GNATS_GROUP} 0600
CONF_FILES_PERMS+=	${EGDIR}/gnatsd.host_access  ${GNATS_HOST_FILE}	\
			${GNATS_USER} ${GNATS_GROUP} 0600
CONF_FILES_PERMS+=	${EGDIR}/databases ${GNATS_DB_FILE}		\
			${GNATS_USER} ${GNATS_GROUP} 0600
CONF_FILES+=		${EGDIR}/send-pr.conf ${PKG_SYSCONFDIR}/send-pr.conf

SPECIAL_PERMS+=		${PREFIX}/libexec/gnats/gen-index \
			${GNATS_USER} ${GNATS_GROUP} 4555
SPECIAL_PERMS+=		${PREFIX}/libexec/gnats/pr-edit \
			${GNATS_USER} ${GNATS_GROUP} 4555

MESSAGE_SUBST+=		PREFIX=${PREFIX:Q}
MESSAGE_SUBST+=		GNATS_USER=${GNATS_USER:Q}
MESSAGE_SUBST+=		GNATS_SERVICE=${GNATS_SERVICE:Q}

SUBST_CLASSES+=		gnats
SUBST_STAGE.gnats=	pre-configure
SUBST_FILES.gnats=	gnats/Makefile.in gnats/ds-file/mkdb.sh
SUBST_SED.gnats=	-e "s,%%EGDIR%%,${DESTDIR}${EGDIR},g"
SUBST_SED.gnats+=	-e "s,%%DESTDIR_GNATS_DEFAULTS%%,${DESTDIR}${PREFIX}/share/gnats/defaults,g"
SUBST_SED.gnats+=	-e "s,%%GNATS_DEFAULTS%%,${PREFIX}/share/gnats/defaults,g"

.include "../../mk/bsd.pkg.mk"

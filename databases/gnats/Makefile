# $NetBSD: Makefile,v 1.22 2005/12/05 23:55:04 rillig Exp $

DISTNAME=	gnats-4.1.0
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GNU:=gnats/}

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gnats/
COMMENT=	GNATS bug tracking system

USE_PKGLOCALEDIR=	yes
USE_PKGINSTALL=		yes
USE_TOOLS+=		gm4 gmake
USE_BISON=		yes
USE_MAKEINFO=		yes
TEXINFO_REQD=		4.6
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-gnats-service=service-name=${GNATS_SERVICE}
CONFIGURE_ARGS+=	--with-gnats-user=${GNATS_USER:Q}
CONFIGURE_ARGS+=	--with-gnatsd-user-access-file=${GNATS_USER_FILE:Q}
CONFIGURE_ARGS+=	--with-gnatsd-host-access-file=${GNATS_HOST_FILE:Q}
CONFIGURE_ARGS+=	--with-gnats-dblist-file=${GNATS_DB_FILE:Q}
CONFIGURE_ARGS+=	--with-gnats-default-db=${GNATS_DBHOME:Q}
CONFIGURE_ARGS+=	--with-lispdir=${PREFIX}/share/gnats

INFO_FILES=	gnats.info gnats-faq.info

PKG_SYSCONFSUBDIR=	gnats

GNATS_USER?=	gnats
GNATS_GROUP?=	daemon
GNATS_SERVICE?=	support
GNATS_HOME?=	${VARBASE}/db/gnats
PKG_USERS=	${GNATS_USER}:${GNATS_GROUP}::GNATS\ database\ owner:${GNATS_HOME}:${SH}

GNATS_USER_FILE?=	${PKG_SYSCONFDIR}/gnatsd.user_access
GNATS_HOST_FILE?=	${PKG_SYSCONFDIR}/gnatsd.host_access
GNATS_DB_FILE?=		${PKG_SYSCONFDIR}/databases
GNATS_DBHOME?=		${GNATS_HOME}/gnatsdb

REQD_DIRS+=		${PREFIX}/share/gnats
REQD_DIRS+=		${PREFIX}/libexec/gnats
REQD_DIRS+=		${EGDIR}
OWN_DIRS_PERMS+=	${GNATS_HOME} gnats daemon 755

EGDIR=			${PREFIX}/share/examples/gnats
CONF_FILES_PERMS+=	${EGDIR}/gnatsd.user_access  ${GNATS_USER_FILE}	\
			${GNATS_USER} ${GNATS_GROUP} 0600
CONF_FILES_PERMS+=	${EGDIR}/gnatsd.host_access  ${GNATS_HOST_FILE}	\
			${GNATS_USER} ${GNATS_GROUP} 0600
CONF_FILES_PERMS+=	${EGDIR}/databases ${GNATS_DB_FILE}		\
			${GNATS_USER} ${GNATS_GROUP} 0600
CONF_FILES+=		${EGDIR}/send-pr.conf ${PKG_SYSCONFDIR}/send-pr.conf

MESSAGE_SUBST+=		PREFIX=${PREFIX}
MESSAGE_SUBST+=		GNATS_USER=${GNATS_USER}
MESSAGE_SUBST+=		GNATS_SERVICE=${GNATS_SERVICE}

SUBST_CLASSES+=		gnats
SUBST_STAGE.gnats=	pre-configure
SUBST_FILES.gnats=	gnats/Makefile.in gnats/mkdb.sh send-pr/Makefile.in
SUBST_SED.gnats=	-e "s,%%EGDIR%%,${EGDIR},g"
SUBST_SED.gnats+=	-e "s,%%GNATS_DEFAULTS%%,${PREFIX}/share/gnats/defaults,g"

.include "../../mk/bsd.pkg.mk"

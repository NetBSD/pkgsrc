# $NetBSD: Makefile,v 1.54 2020/11/05 09:09:04 ryoon Exp $
#

DISTNAME=		prelude-manager-0.9.15
PKGREVISION=		16
CATEGORIES=		security
MASTER_SITES=		http://www.prelude-ids.com/download/releases/prelude-manager/
#MASTER_SITES+=		http://www.prelude-ids.org/download/releases/
#MASTER_SITES+=		http://www.prelude-ids.org/download/releases/old/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://www.prelude-ids.org/download/releases/
COMMENT=		Prelude IDS manager

.include "../../mk/bsd.prefs.mk"

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		make
USE_LANGUAGES=		c c++
BUILD_DEFS+=		VARBASE
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--with-libpreludedb-prefix=${BUILDLINK_PREFIX.libpreludedb}

RCD_SCRIPTS=			preludemanager
PRELUDE_MANAGER_PID_DIR=	${VARBASE}/run/prelude-manager
PRELUDE_USER?=			_prelude
PRELUDE_GROUP?=			_prelude
PRELUDE_HOME?=			${VARBASE}/spool/prelude-manager
OWN_DIRS_PERMS+=		${PRELUDE_HOME} ${PRELUDE_USER} ${PRELUDE_GROUP} 750
OWN_DIRS+=			${PKG_SYSCONFDIR}/prelude-manager

INSTALLATION_DIRS=	sbin

PKG_GROUPS_VARS+=	PRELUDE_GROUP
PKG_USERS_VARS+=	PRELUDE_USER

PKG_GROUPS=		${PRELUDE_GROUP}
PKG_USERS=		${PRELUDE_USER}:${PRELUDE_GROUP}

PKG_GECOS.${PRELUDE_USER}=	Prelude IDS manager
PKG_HOME.${PRELUDE_USER}=	${PRELUDE_HOME}

FILES_SUBST+=		PRELUDE_MANAGER_PID_DIR=${PRELUDE_MANAGER_PID_DIR:Q}
FILES_SUBST+=		PRELUDE_USER=${PRELUDE_USER:Q}
FILES_SUBST+=		PRELUDE_GROUP=${PRELUDE_USER:Q}

SUBST_CLASSES+=		code
SUBST_STAGE.code=	pre-configure
SUBST_FILES.code=	run-prelude-manager.c
SUBST_VARS.code=	PREFIX
SUBST_VARS.code+=	PRELUDE_USER

EGDIR=			share/examples/prelude-manager/
CONF_FILES+=		${EGDIR}/prelude-manager.conf ${PKG_SYSCONFDIR}/prelude-manager/prelude-manager.conf

pre-patch:
	${CP} ${FILESDIR}/run-prelude-manager.c ${WRKSRC}

pre-configure:
	${LN} -s ${BUILDLINK_DIR}/lib/libltdl.so ${BUILDLINK_DIR}/lib/libltdlc.so

post-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${CC} ${CFLAGS} -o run-prelude-manager run-prelude-manager.c

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/run-prelude-manager ${DESTDIR}${PREFIX}/sbin/run-prelude-manager

.include "../../security/gnutls/buildlink3.mk"
.include "../../security/gnutls/libgnutls-config.mk"
.include "../../security/libprelude/buildlink3.mk"
.include "../../security/libpreludedb/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

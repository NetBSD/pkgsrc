# $NetBSD: Makefile,v 1.11 2006/08/23 11:19:58 shannonjr Exp $
#

DISTNAME=		prelude-manager-0.9.5
PKGREVISION=		2
CATEGORIES=		security
MASTER_SITES=		http://www.prelude-ids.org/download/releases/

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		http://www.prelude-ids.org/download/releases/
COMMENT=		Prelude IDS manager

.include "../../mk/bsd.prefs.mk"

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		make
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--with-libpreludedb-prefix=${BUILDLINK_PREFIX.libpreludedb}
RCD_SCRIPTS=		preludemanager
PRELUDE_MANAGER_PID_DIR=	${VARBASE}/run/prelude-manager
PRELUDE_USER?=		_prelude
PRELUDE_GROUP?=		_prelude
PRELUDE_HOME?=		/var/spool/prelude-manager

PKG_GROUPS=     ${PRELUDE_GROUP}
PKG_USERS=      ${PRELUDE_USER}:${PRELUDE_GROUP}

PKG_GECOS.${PRELUDE_USER}=	Prelude IDS manager
PKG_HOME.${PRELUDE_USER}=	${PRELUDE_HOME}

FILES_SUBST+=	PRELUDE_MANAGER_PID_DIR=${PRELUDE_MANAGER_PID_DIR:Q}
FILES_SUBST+=   PRELUDE_USER=${PRELUDE_USER:Q}
FILES_SUBST+=   PRELUDE_GROUP=${PRELUDE_USER:Q}

SUBST_CLASSES+=         code
SUBST_STAGE.code=       post-patch
SUBST_FILES.code=       run-prelude-manager.c
SUBST_SED.code=         -e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.code+=        -e 's,@PRELUDE_USER@,${PRELUDE_USER},g'

EGDIR=			share/examples/prelude-manager/
CONF_FILES_PERMS+=	${EGDIR}/prelude-manager.conf ${PKG_SYSCONFDIR}/prelude-manager/prelude-manager.conf \
			${ROOT_USER} ${ROOT_GROUP} 0600

pre-patch:
	${CP} ${FILESDIR}/run-prelude-manager.c ${WRKSRC}

post-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${CC} ${CFLAGS} -o run-prelude-manager run-prelude-manager.c

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/run-prelude-manager ${PREFIX}/sbin/run-prelude-manager
	${CHOWN} -R ${PRELUDE_USER}:${PRELUDE_GROUP} ${PRELUDE_HOME}

.include "../../security/libprelude/buildlink3.mk"
.include "../../security/libpreludedb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

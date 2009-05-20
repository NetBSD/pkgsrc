# $NetBSD: Makefile,v 1.2 2009/05/20 00:58:27 wiz Exp $
#

DISTNAME=	prelude-correlator-0.9.0-beta3
PKGNAME=	prelude-correlator-${DISTNAME:S/-beta/beta/:C/.*-//}
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.prelude-ids.com/download/releases/prelude-correlator/

MAINTAINER=	shannonjr@NetBSD.org
HOMEPAGE=	http://www.prelude-ids.com/download/releases/prelude-correlator/
COMMENT=	Intrusion event correlation engine

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		make
USE_TOOLS+=		pkg-config
BUILD_DEFS+=		VARBASE
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--with-libpreludedb-prefix=${BUILDLINK_PREFIX.libpreludedb}
RCD_SCRIPTS=		preludecorrelator
PRELUDE_CORRELATOR_PID_DIR=	${VARBASE}/run/prelude-correlator
PRELUDE_USER?=		_prelude
PRELUDE_GROUP?=		_prelude
PRELUDE_HOME?=		${VARBASE}/prelude-correlator

INSTALLATION_DIRS=	sbin

PKG_GROUPS_VARS+=	PRELUDE_GROUP
PKG_USERS_VARS+=	PRELUDE_USER

PKG_GROUPS=		${PRELUDE_GROUP}
PKG_USERS=		${PRELUDE_USER}:${PRELUDE_GROUP}

PKG_GECOS.${PRELUDE_USER}=	Prelude IDS correlator
PKG_HOME.${PRELUDE_USER}=	${PRELUDE_HOME}

FILES_SUBST+=   PRELUDE_CORRELATOR_PID_DIR=${PRELUDE_CORRELATOR_PID_DIR:Q}
FILES_SUBST+=   PRELUDE_USER=${PRELUDE_USER:Q}
FILES_SUBST+=   PRELUDE_GROUP=${PRELUDE_USER:Q}

EGDIR=			share/examples/prelude-correlator/
REQD_DIRS=		${EGDIR}
REQD_DIRS+=		${EGDIR}/lua-rules
CONF_FILES_PERMS+=	${EGDIR}/prelude-correlator.conf ${PKG_SYSCONFDIR}/prelude-correlator/prelude-correlator.conf \
			${ROOT_USER} ${ROOT_GROUP} 0644

SUBST_CLASSES+=		code
SUBST_STAGE.code=	post-patch
SUBST_FILES.code=	run-prelude-correlator.c
SUBST_SED.code=		-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.code+=	-e 's,@PRELUDE_USER@,${PRELUDE_USER},g'

SUBST_CLASSES+=		make
SUBST_STAGE.make=	post-patch
SUBST_FILES.make=	Makefile.in
SUBST_SED.make=		-e 's,@EGDIR@,${EGDIR},g'

pre-patch:
	${CP} ${FILESDIR}/run-prelude-correlator.c ${WRKSRC}

post-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${CC} ${CFLAGS} -o run-prelude-correlator run-prelude-correlator.c

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/run-prelude-correlator ${PREFIX}/sbin/run-prelude-correlator
	${CHOWN} -R ${PRELUDE_USER}:${PRELUDE_GROUP} ${PRELUDE_HOME}

.include "../../security/libprelude/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

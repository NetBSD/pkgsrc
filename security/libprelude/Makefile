# $NetBSD: Makefile,v 1.30 2008/04/28 10:51:49 shannonjr Exp $
#
DISTNAME=		libprelude-0.9.17
CATEGORIES=		security
MASTER_SITES=		http://www.prelude-ids.org/download/releases/ \
			http://www.prelude-ids.org/download/releases/old/

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		http://www.prelude-ids.org/download/releases/
COMMENT=		Provides the framework for using the Prelude system

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

PRELUDE_USER?=		_prelude
PRELUDE_GROUP?=		_prelude

PKG_GROUPS_VARS+=	PRELUDE_GROUP
PKG_USERS_VARS+=	PRELUDE_USER

BUILD_DEFS+=		VARBASE

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		chown make bison gawk gmake
PKG_SYSCONFSUBDIR=	prelude
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc
PRELUDE_USER?=		_prelude
PRELUDE_GROUP?=		_prelude
PRELUDE_HOME?=		${VARBASE}/spool/prelude

PKG_GROUPS=	${PRELUDE_GROUP}
PKG_USERS=	${PRELUDE_USER}:${PRELUDE_GROUP}

PKG_GECOS.${PRELUDE_USER}=	Prelude IDS
PKG_HOME.${PRELUDE_USER}=	${PRELUDE_HOME}

EGDIR=		${PREFIX}/share/examples/libprelude
REQD_DIRS=	${EGDIR}
MAKE_DIRS=	${PKG_SYSCONFDIR}/default ${PKG_SYSCONFDIR}/profile
MAKE_DIRS_PERMS+=	${PKG_SYSCONFDIR}/profile ${ROOT_USER} ${ROOT_GROUP} 0711

CONF_FILES+=	${PREFIX}/share/examples/libprelude/client.conf ${PKG_SYSCONFDIR}/default/client.conf
CONF_FILES+=	${PREFIX}/share/examples/libprelude/global.conf ${PKG_SYSCONFDIR}/default/global.conf
CONF_FILES+=	${PREFIX}/share/examples/libprelude/idmef-client.conf ${PKG_SYSCONFDIR}/default/idmef-client.conf
CONF_FILES+=	${PREFIX}/share/examples/libprelude/tls.conf ${PKG_SYSCONFDIR}/default/tls.conf

SUBST_CLASSES+=		make
SUBST_STAGE.make=	post-patch
SUBST_FILES.make=	Makefile.in
SUBST_SED.make=		-e 's,@EGDIR@,${EGDIR},g'

post-install:
	chown -R ${PRELUDE_USER}:${PRELUDE_GROUP} ${PRELUDE_HOME}

.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

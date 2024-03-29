# $NetBSD: Makefile,v 1.72 2023/07/09 10:02:38 nia Exp $

DISTNAME=	silc-server-1.1.18
PKGREVISION=	2
CATEGORIES=	chat security
MASTER_SITES=	http://www.silcnet.org/download/server/sources/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://www.silcnet.org/
COMMENT=	Server for the Secure Internet Live Conferencing (SILC) protocol

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-optimizations
CONFIGURE_ARGS+=	--with-logsdir=${VARBASE}/log/silcd
CONFIGURE_ARGS+=	--with-silc-includes=${BUILDLINK_PREFIX.silc-toolkit}/include/silc
CONFIGURE_ARGS+=	--with-silc-libs=${BUILDLINK_PREFIX.silc-toolkit}/libs
CONFIGURE_ARGS+=	--with-silcd-config-file=${PKG_SYSCONFDIR}/silcd.conf
CONFIGURE_ARGS+=	--with-silcd-pid-file=${VARBASE}/run/silcd.pid
CONFIGURE_ARGS+=	--without-gmp
CONFIGURE_ARGS+=	--without-iconv
#.if ${MACHINE_ARCH} != "i386"
#CONFIGURE_ARGS+=	--disable-asm
#.endif

CONFIGURE_ENV+=		ac_cv_lib_gmp___gmpz_init=no
CONFIGURE_ENV+=		ac_cv_func_iconv=no

.include "../../mk/bsd.prefs.mk"

SILCD_USER?=		silcd
SILCD_GROUP?=		silcd
PKG_GROUPS=		${SILCD_GROUP}
PKG_USERS=		${SILCD_USER}:${SILCD_GROUP}
PKG_USERS_VARS+=	SILCD_USER
PKG_GROUPS_VARS+=	SILCD_GROUP

PKG_SYSCONFSUBDIR?=	${PKGBASE}

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
MAKE_ENV+=		examplesdir=${EGDIR}

CONF_FILES_MODE=	0600
CONF_FILES+=		${EGDIR}/silcd.conf.default \
			${PKG_SYSCONFDIR}/silcd.conf
CONF_FILES+=		${EGDIR}/silcalgs.conf.default \
			${PKG_SYSCONFDIR}/silcalgs.conf
CONF_FILES_PERMS+=	${EGDIR}/motd.txt.default ${PKG_SYSCONFDIR}/motd.txt \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0644

RCD_SCRIPTS=		silcd

.if ${OPSYS} == "NetBSD"
RCD_SCRIPT_SRC.silcd=	${FILESDIR}/silcd.sh
.else
RCD_SCRIPT_SRC.silcd=	${FILESDIR}/silcd.generic
.endif

BUILD_DEFS+=		VARBASE
OWN_DIRS_PERMS+=	${VARBASE}/log/silcd ${SILCD_USER} ${SILCD_GROUP} 0700

.include "options.mk"

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	motd.txt
SUBST_VARS.paths=	PREFIX

post-extract:
	${CP} ${FILESDIR}/motd.txt ${WRKSRC}

INSTALLATION_DIRS+=	${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/motd.txt ${DESTDIR}${EGDIR}/motd.txt.default

.include "../../devel/silc-toolkit/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.62 2010/02/19 21:01:36 joerg Exp $
#

DISTNAME=		silc-server-1.1.6
PKGREVISION=		1
CATEGORIES=		chat security
MASTER_SITES=		http://www.silcnet.org/download/server/sources/ \
			ftp://ftp.silcnet.org/silc/server/sources/ 
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		salo@NetBSD.org
HOMEPAGE=		http://www.silcnet.org/
COMMENT=		Server for the Secure Internet Live Conferencing (SILC) protocol

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
OVERRIDE_DIRDEPTH=	3
SHLIBTOOL_OVERRIDE=	# empty

.include "../../mk/bsd.prefs.mk"

SILCD_USER?=		silcd
SILCD_GROUP?=		silcd
PKG_GROUPS=		${SILCD_GROUP}
PKG_USERS=		${SILCD_USER}:${SILCD_GROUP}
PKG_USERS_VARS+=	SILCD_USER
PKG_GROUPS_VARS+=	SILCD_GROUP

PKG_SYSCONFSUBDIR?=	${PKGBASE}

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
MAKE_ENV+=		examplesdir=${EGDIR:Q}

CONF_FILES_MODE=	0600
CONF_FILES+=		${EGDIR}/silcd.conf.default \
			${PKG_SYSCONFDIR}/silcd.conf
CONF_FILES+=		${EGDIR}/silcalgs.conf.default \
			${PKG_SYSCONFDIR}/silcalgs.conf
CONF_FILES_PERMS+=	${EGDIR}/motd.txt.default ${PKG_SYSCONFDIR}/motd.txt \
			${REAL_ROOT_USER} ${ROOT_GROUP} 0644

RCD_SCRIPTS=		silcd

.if ${OPSYS} == "NetBSD"
RCD_SCRIPT_SRC.silcd=	${FILESDIR}/silcd.sh
.else
RCD_SCRIPT_SRC.silcd=	${FILESDIR}/silcd.generic
.endif

BUILD_DEFS+=		VARBASE

OWN_DIRS_PERMS+=	${VARBASE}/log/silcd ${SILCD_USER} ${SILCD_GROUP} 0700

CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/${PKGBASE}
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/${PKGBASE}
CONFIGURE_ARGS+=	--with-etcdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-silcd-config-file=${PKG_SYSCONFDIR}/silcd.conf
CONFIGURE_ARGS+=	--with-simdir=${PREFIX}/lib/${PKGBASE}/modules
CONFIGURE_ARGS+=	--with-logsdir=${VARBASE}/log/silcd
CONFIGURE_ARGS+=	--with-silcd-pid-file=${VARBASE}/run/silcd.pid
CONFIGURE_ARGS+=	--without-iconv
CONFIGURE_ARGS+=	--without-libtoolfix
# Doesn't work -- shared libraries are not installed
#CONFIGURE_ARGS+=	--enable-shared

.if ${MACHINE_ARCH} != "i386"
CONFIGURE_ARGS+=	--disable-asm
.endif

.include "options.mk"

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	motd.txt
SUBST_SED.paths=	-e 's,@PREFIX@,${PREFIX},'

post-extract:
	${CP} ${FILESDIR}/motd.txt ${WRKSRC}

INSTALLATION_DIRS+=	${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/motd.txt ${DESTDIR}${EGDIR}/motd.txt.default

.include "../../mk/bsd.pkg.mk"

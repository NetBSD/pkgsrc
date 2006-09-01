# $NetBSD: Makefile,v 1.3 2006/09/01 20:58:48 rillig Exp $

DISTNAME=		kismet-2006-04-R1
PKGNAME=		kismet-2006.04.01
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		http://www.kismetwireless.net/code/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.kismetwireless.net/
COMMENT=		802.11 wireless network detector, sniffer and IDS

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_NCURSES=		# needs libpanel
USE_TOOLS+=		gmake perl:run
REPLACE_PERL+=		scripts/gpsmap-helper-earthamaps

# might be appended to in options.mk
PLIST_SRC=		PLIST

KISMET_USER?=		kismet
KISMET_GROUP?=		kismet
PKG_GROUPS=		${KISMET_GROUP}
PKG_USERS=		${KISMET_USER}:${KISMET_GROUP}::Kismet\ user:${VARBASE}/log/kismet

PKG_SYSCONFSUBDIR?=	${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES+=		${EGDIR}/ap_manuf ${PKG_SYSCONFDIR}/ap_manuf
CONF_FILES+=		${EGDIR}/client_manuf ${PKG_SYSCONFDIR}/client_manuf
CONF_FILES+=		${EGDIR}/kismet.conf.default		\
				${PKG_SYSCONFDIR}/kismet.conf
CONF_FILES+=		${EGDIR}/kismet_drone.conf.default	\
				${PKG_SYSCONFDIR}/kismet_drone.conf
CONF_FILES+=		${EGDIR}/kismet_ui.conf.default		\
				${PKG_SYSCONFDIR}/kismet_ui.conf
OWN_DIRS_PERMS+=	${VARBASE}/log/kismet ${KISMET_USER} ${KISMET_GROUP} 0700

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

SUBST_CLASSES+=		user
SUBST_MESSAGE.user=	Fixing user name.
SUBST_STAGE.user=	pre-configure
SUBST_FILES.user=	conf/kismet.conf.in
SUBST_SED.user=		's/your_user_here/${KISMET_USER}/'

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/ap_manuf ${EGDIR}/
	${INSTALL_DATA} ${WRKSRC}/conf/client_manuf ${EGDIR}/
	${INSTALL_DATA} ${WRKSRC}/conf/kismet.conf		\
		${EGDIR}/kismet.conf.default
	${INSTALL_DATA} ${WRKSRC}/conf/kismet_drone.conf	\
		${EGDIR}/kismet_drone.conf.default
	${INSTALL_DATA} ${WRKSRC}/conf/kismet_ui.conf		\
		${EGDIR}/kismet_ui.conf.default

.include "options.mk"

.include "../../devel/glib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.50 2010/02/17 15:21:36 joerg Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

PKGNAME=		ups-${DISTNAME}
COMMENT=		Network UPS Tools

CONFIGURE_ARGS+=	--with-user=${NUT_USER:Q}
CONFIGURE_ARGS+=	--with-group=${NUT_GROUP:Q}
CONFIGURE_ARGS+=	--with-drvpath=${NUT_DRVDIR:Q}
CONFIGURE_ARGS+=	--with-altpidpath=${NUT_STATEDIR:Q}
CONFIGURE_ARGS+=	--with-pidpath=${NUT_STATEDIR:Q}

NUT_USER?=		nut
NUT_GROUP?=		nut

PKG_GROUPS_VARS+=	NUT_GROUP
PKG_USERS_VARS+=	NUT_USER
BUILD_DEFS+=		NUT_STATEDIR

FILES_SUBST+=		NUT_CONFDIR=${NUT_CONFDIR:Q}
FILES_SUBST+=		NUT_STATEDIR=${NUT_STATEDIR:Q}

MESSAGE_SUBST+=		NUT_CONFDIR=${NUT_CONFDIR}
MESSAGE_SUBST+=		NUT_EGDIR=${NUT_EGDIR}
MESSAGE_SUBST+=		NUT_DOCDIR=${NUT_DOCDIR}

PKG_GROUPS=		${NUT_GROUP}
PKG_USERS=		${NUT_USER}:${NUT_GROUP}
PKG_GECOS.${NUT_USER}=	Network UPS Tools
PKG_HOME.${NUT_USER}=	${NUT_STATEDIR}
PKG_SHELL.${NUT_USER}=	${SH}

CONF_FILES=		${NUT_EGDIR}/ups.conf.sample ${NUT_CONFDIR}/ups.conf
CONF_FILES+=		${NUT_EGDIR}/upssched.conf.sample 		\
			${NUT_CONFDIR}/upssched.conf

CONF_FILES_PERMS=	${NUT_EGDIR}/upsd.conf.sample			\
			${NUT_CONFDIR}/upsd.conf			\
			${ROOT_USER} ${ROOT_GROUP} 0600
CONF_FILES_PERMS+=	${NUT_EGDIR}/upsd.users.sample			\
			${NUT_CONFDIR}/upsd.users			\
			${ROOT_USER} ${ROOT_GROUP} 0600
CONF_FILES_PERMS+=	${NUT_EGDIR}/upsmon.conf.sample			\
			${NUT_CONFDIR}/upsmon.conf			\
			${ROOT_USER} ${ROOT_GROUP} 0600
RCD_SCRIPTS=		ups upsd upsdriver upslog upsmon

OWN_DIRS=		${NUT_CONFDIR}
OWN_DIRS_PERMS=		${NUT_STATEDIR} ${NUT_USER} ${NUT_GROUP} 0770

INSTALLATION_DIRS+=	${NUT_EGDIR} ${NUT_DOCDIR}/cables ${NUT_DOCDIR}/drivers

post-install:
	${INSTALL_DATA_DIR} 
	for f in COPYING CREDITS ChangeLog NEWS README INSTALL UPGRADING; do \
		${INSTALL_DATA} ${WRKSRC}/$$f ${DESTDIR}${NUT_DOCDIR}; \
	done
	${INSTALL_DATA} ${WRKSRC}/docs/FAQ ${DESTDIR}${NUT_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/data/driver.list ${DESTDIR}${NUT_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${DESTDIR}${NUT_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/cables/*.txt ${DESTDIR}${NUT_DOCDIR}/cables

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.30 2004/04/05 22:38:09 martin Exp $
#

DISTNAME=		nut-2.0.0
PKGNAME=		ups-nut-2.0.0
CATEGORIES=		sysutils
MASTER_SITES=		http://random.networkupstools.org/source/2.0/

MAINTAINER=		lukem@NetBSD.org
HOMEPAGE=		http://www.networkupstools.org/
COMMENT=		Network UPS Tools

USE_BUILDLINK2=		yes
USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${NUT_CONFDIR}			\
			--datadir=${NUT_DATADIR}			\
			--localstatedir=${NUT_STATEDIR}			\
			--with-user=${NUT_USER}				\
			--with-group=${NUT_GROUP}			\
			--with-statepath=${NUT_STATEDIR}		\
			--with-drvpath=${NUT_DRVDIR}			\
			--with-altpidpath=${NUT_STATEDIR}		\
			--with-pidpath=${NUT_STATEDIR}

PKG_SYSCONFSUBDIR?=	nut
NUT_CONFDIR=		${PKG_SYSCONFDIR}
NUT_DATADIR=		${PREFIX}/share/nut
NUT_DOCDIR=		${PREFIX}/share/doc/nut
NUT_DRVDIR=		${PREFIX}/libexec/nut
NUT_EGDIR=		${PREFIX}/share/examples/nut
NUT_STATEDIR=		/var/db/nut

NUT_USER?=		nut
NUT_GROUP?=		nut

FILES_SUBST+=		NUT_CONFDIR=${NUT_CONFDIR}
FILES_SUBST+=		NUT_STATEDIR=${NUT_STATEDIR}

MESSAGE_SUBST+=		NUT_CONFDIR=${NUT_CONFDIR}
MESSAGE_SUBST+=		NUT_EGDIR=${NUT_EGDIR}
MESSAGE_SUBST+=		NUT_DOCDIR=${NUT_DOCDIR}

PKG_GROUPS=		${NUT_GROUP}
PKG_USERS=		${NUT_USER}:${NUT_GROUP}::Network\\ UPS\\ Tools::${SH}

CONF_FILES=		${NUT_EGDIR}/ups.conf.sample ${NUT_CONFDIR}/ups.conf
CONF_FILES+=		${NUT_EGDIR}/upssched.conf.sample \
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

pre-install:
	@${MKDIR} ${NUT_STATEDIR}
	@${MKDIR} ${NUT_DRVDIR}
	@${CHOWN} ${NUT_USER} ${NUT_STATEDIR}
	${INSTALL_DATA_DIR} ${NUT_EGDIR}

post-install:
	${INSTALL_DATA_DIR} ${NUT_DOCDIR}
	${INSTALL_DATA_DIR} ${NUT_DOCDIR}/cables ${NUT_DOCDIR}/drivers
	for f in CHANGES COPYING CREDITS NEWS README INSTALL UPGRADING; do \
		${INSTALL_DATA} ${WRKSRC}/$$f ${NUT_DOCDIR}; \
	done
	${INSTALL_DATA} ${WRKSRC}/docs/FAQ ${NUT_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/data/driver.list ${NUT_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${NUT_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/cables/*.txt ${NUT_DOCDIR}/cables

.include "../../mk/bsd.pkg.mk"

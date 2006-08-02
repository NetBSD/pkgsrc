# $NetBSD: Makefile,v 1.43 2006/08/02 12:30:22 ghen Exp $
#

DISTNAME=		nut-2.0.3
PKGNAME=		ups-nut-2.0.3
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		http://random.networkupstools.org/source/2.0/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.networkupstools.org/
COMMENT=		Network UPS Tools

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${NUT_CONFDIR:Q}			\
			--datadir=${NUT_DATADIR:Q}			\
			--localstatedir=${NUT_STATEDIR:Q}		\
			--with-user=${NUT_USER:Q}			\
			--with-group=${NUT_GROUP:Q}			\
			--with-statepath=${NUT_STATEDIR:Q}		\
			--with-drvpath=${NUT_DRVDIR:Q}			\
			--with-altpidpath=${NUT_STATEDIR:Q}		\
			--with-pidpath=${NUT_STATEDIR:Q}

PKG_SYSCONFSUBDIR?=	nut
NUT_CONFDIR=		${PKG_SYSCONFDIR}
NUT_DATADIR=		${PREFIX}/share/nut
NUT_DOCDIR=		${PREFIX}/share/doc/nut
NUT_DRVDIR=		${PREFIX}/libexec/nut
NUT_EGDIR=		${PREFIX}/share/examples/nut
NUT_STATEDIR?=		${VARBASE}/db/nut

NUT_USER?=		nut
NUT_GROUP?=		nut

BUILD_DEFS+=		NUT_STATEDIR NUT_USER NUT_GROUP

FILES_SUBST+=		NUT_CONFDIR=${NUT_CONFDIR:Q}
FILES_SUBST+=		NUT_STATEDIR=${NUT_STATEDIR:Q}

MESSAGE_SUBST+=		NUT_CONFDIR=${NUT_CONFDIR}
MESSAGE_SUBST+=		NUT_EGDIR=${NUT_EGDIR}
MESSAGE_SUBST+=		NUT_DOCDIR=${NUT_DOCDIR}

PKG_GROUPS=		${NUT_GROUP}
PKG_USERS=		${NUT_USER}:${NUT_GROUP}
PKG_GECOS.${NUT_USER}=	Network UPS Tools
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

# $NetBSD: Makefile,v 1.14 2001/11/21 15:50:55 jlam Exp $
#

DISTNAME=		nut-0.45.2
PKGNAME=		ups-nut-0.45.2
CATEGORIES=		sysutils
MASTER_SITES=		http://www.exploits.org/nut/release/

MAINTAINER=		lukem@netbsd.org
HOMEPAGE=		http://www.exploits.org/nut/
COMMENT=		Network UPS Tools

BUILD_DEPENDS+=		autoconf>=2.13:../../devel/autoconf

USE_BUILDLINK_ONLY=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${NUT_CONFDIR}			\
			--with-user=${PKG_USER}				\
			--with-group=${PKG_GROUP}			\
			--with-statepath=${NUT_STATEDIR}		\
			--with-modelpath=${LOCALBASE}/sbin/ups-drivers

NUT_CONFDIR=		${CONFDIR}/nut
NUT_DOCDIR=		${PREFIX}/share/doc/nut
NUT_EGDIR=		${PREFIX}/share/examples/nut
NUT_STATEDIR=		/var/db/nut

FILES_SUBST+=		NUT_CONFDIR=${NUT_CONFDIR}
FILES_SUBST+=		NUT_STATEDIR=${NUT_STATEDIR}

PKG_USER=		nut
PKG_USER_DESCR=		Network UPS Tools
PKG_USER_SHELL=		${SH}
PKG_GROUP=		nut

CONF_FILES=	${NUT_EGDIR}/hosts.conf.sample ${NUT_CONFDIR}/hosts.conf
CONF_FILES+=	${NUT_EGDIR}/multimon.conf.sample ${NUT_CONFDIR}/multimon.conf
CONF_FILES+=	${NUT_EGDIR}/upsset.conf.sample ${NUT_CONFDIR}/upsset.conf
CONF_FILES+=	${NUT_EGDIR}/upssched.conf.sample ${NUT_CONFDIR}/upssched.conf
CONF_FILES+=	${NUT_EGDIR}/ups.conf.sample ${NUT_CONFDIR}/ups.conf

CONF_FILES_PERMS=	${NUT_EGDIR}/upsmon.conf.sample			\
			${NUT_CONFDIR}/upsmon.conf			\
			${ROOT_USER} ${ROOT_GROUP} 0600
CONF_FILES_PERMS+=	${NUT_EGDIR}/upsd.conf.sample			\
			${NUT_CONFDIR}/upsd.conf			\
			${ROOT_USER} ${ROOT_GROUP} 0600
CONF_FILES_PERMS+=	${NUT_EGDIR}/upsd.users.sample			\
			${NUT_CONFDIR}/upsd.users			\
			${ROOT_USER} ${ROOT_GROUP} 0600
RCD_SCRIPTS=		ups upsd upsdriver upslog upsmon

OWN_DIRS=		${NUT_CONFDIR}
OWN_DIRS_PERMS=		${NUT_STATEDIR} ${PKG_USER} ${PKG_GROUP} 0770

pre-configure:
	cd ${WRKSRC}; ${LOCALBASE}/bin/autoreconf --force

pre-install:
	@${INSTALL_DATA_DIR} ${NUT_EGDIR}
	@for script in ${RCD_SCRIPTS}; do				\
		${SED} ${FILES_SUBST_SED} ${FILESDIR}/$${script}.sh	\
			> ${WRKDIR}/$${script};				\
	done
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} PRE-INSTALL

post-install:
	for script in ${RCD_SCRIPTS}; do				\
		${INSTALL_SCRIPT} ${WRKDIR}/$${script}			\
			${PREFIX}/etc/rc.d/$${script};			\
	done
	${INSTALL_DATA_DIR} ${NUT_DOCDIR} ${NUT_DOCDIR}/cables
	${INSTALL_DATA} ${WRKSRC}/docs/cables/*.txt ${NUT_DOCDIR}/cables
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${NUT_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/FAQ ${NUT_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/Changes.trust ${NUT_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${NUT_DOCDIR}
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.66 2022/08/11 16:00:17 gdt Exp $

PKGREVISION= 2
.include "Makefile.common"

PKGNAME=		ups-${DISTNAME}
COMMENT=		Network UPS Tools

SUBST_CLASSES+=		man-so
SUBST_MESSAGE.man-so=	Fixing manpage .so references.
SUBST_STAGE.man-so=	pre-build
SUBST_FILES.man-so=	docs/man/*.[0-9]
SUBST_SED.man-so=	-e 's,^\.so \([^/]*\)\.\([0-9]\)$$,.so man\2/\1.\2,'
SUBST_NOOP_OK.man-so=	yes

# Don't regenerate any files in tools/.
TOOLS_SCRIPT.perl=	exit 1

CONFIGURE_ARGS+=	--with-drvpath=${NUT_DRVDIR:Q}
CONFIGURE_ARGS+=	--with-altpidpath=${NUT_STATEDIR:Q}
CONFIGURE_ARGS+=	--with-pidpath=${NUT_STATEDIR:Q}
CONFIGURE_ARGS+=	--with-dev

PKG_GROUPS_VARS+=	NUT_GROUP
PKG_USERS_VARS+=	NUT_USER
BUILD_DEFS+=		NUT_STATEDIR VARBASE

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

CONF_FILES=		${NUT_EGDIR}/nut.conf.sample ${NUT_CONFDIR}/nut.conf
CONF_FILES+=		${NUT_EGDIR}/ups.conf.sample ${NUT_CONFDIR}/ups.conf
CONF_FILES+=		${NUT_EGDIR}/upssched.conf.sample 		\
			${NUT_CONFDIR}/upssched.conf

CONF_FILES_PERMS=	${NUT_EGDIR}/upsd.conf.sample			\
			${NUT_CONFDIR}/upsd.conf			\
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0600
CONF_FILES_PERMS+=	${NUT_EGDIR}/upsd.users.sample			\
			${NUT_CONFDIR}/upsd.users			\
			${NUT_USER} ${NUT_GROUP} 0600
CONF_FILES_PERMS+=	${NUT_EGDIR}/upsmon.conf.sample			\
			${NUT_CONFDIR}/upsmon.conf			\
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0600
RCD_SCRIPTS=		ups upsd upsdriver upslog upsmon

OWN_DIRS=		${NUT_CONFDIR}
OWN_DIRS_PERMS=		${NUT_STATEDIR} ${NUT_USER} ${NUT_GROUP} 0770

INSTALLATION_DIRS+=	${NUT_EGDIR} ${NUT_DOCDIR}/cables ${NUT_DOCDIR}/drivers

CHECK_INTERPRETER_SKIP+=	share/nut/solaris-init/nut

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${NUT_EGDIR}
	${MV} ${DESTDIR}${NUT_CONFDIR}/*.sample ${DESTDIR}${NUT_EGDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${NUT_DOCDIR}
	for f in COPYING CREDITS ChangeLog NEWS README INSTALL UPGRADING; do \
		${INSTALL_DATA} ${WRKSRC}/$$f ${DESTDIR}${NUT_DOCDIR}; \
	done
	for f in ${WRKSRC}/docs/*.txt; do \
		${INSTALL_DATA} $$f ${DESTDIR}${NUT_DOCDIR}; \
	done
	for f in ${WRKSRC}/docs/cables/*.txt; do \
		${INSTALL_DATA} $$f ${DESTDIR}${NUT_DOCDIR}/cables/; \
	done

# nut-scanner needs libltdl, but this is not documented
.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.74 2023/11/09 21:02:48 gdt Exp $

.include "Makefile.common"

PKGNAME=		ups-${DISTNAME}
PKGREVISION=		2
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
CONFIGURE_ARGS+=	--with-pidpath=${NUT_STATEDIR:Q}
CONFIGURE_ARGS+=	--with-altpidpath=${NUT_STATEDIR:Q}

# nut, bizarrely, does not install headers by default
CONFIGURE_ARGS+=	--with-dev
CONFIGURE_ARGS+=	--without-asciidoc

CONFIGURE_ARGS+=	--without-snmp		# provided by sysutils/ups-nut-snmp
CONFIGURE_ARGS+=	--without-usb		# provided by sysutils/ups-nut-usb
CONFIGURE_ARGS+=	--without-nut_monitor	# not yet packaged

# Disable python2 to workaround
# https://github.com/networkupstools/nut/issues/1792 which upstream
# declines to fix.
CONFIGURE_ARGS+=	--without-python2
CONFIGURE_ARGS+=	--with-python=${PYTHONBIN}
# \todo Move to split package.

PKG_GROUPS_VARS+=	NUT_GROUP
PKG_USERS_VARS+=	NUT_USER
BUILD_DEFS+=		NUT_STATEDIR VARBASE

FILES_SUBST+=		NUT_CONFDIR=${NUT_CONFDIR:Q}
FILES_SUBST+=		NUT_STATEDIR=${NUT_STATEDIR:Q}

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
RCD_SCRIPTS=		ups upskillpower upsdriver upsd upsmon upslog

PY_PATCHPLIST=		yes

OWN_DIRS=		${NUT_CONFDIR}
OWN_DIRS_PERMS=		${NUT_STATEDIR} ${NUT_USER} ${NUT_GROUP} 0770

INSTALLATION_DIRS+=	${NUT_EGDIR} ${NUT_DOCDIR}/cables ${NUT_DOCDIR}/drivers

CHECK_INTERPRETER_SKIP+=	share/nut/solaris-init/nut

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${NUT_EGDIR}
	${MV} ${DESTDIR}${NUT_CONFDIR}/*.sample ${DESTDIR}${NUT_EGDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${NUT_DOCDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${NUT_DOCDIR}/detailed
	for f in AUTHORS COPYING ChangeLog NEWS.adoc README.adoc UPGRADING.adoc; do \
		${INSTALL_DATA} ${WRKSRC}/$$f ${DESTDIR}${NUT_DOCDIR}; \
	done
	for f in ${WRKSRC}/docs/*.txt; do \
		${INSTALL_DATA} $$f ${DESTDIR}${NUT_DOCDIR}/detailed; \
	done
	for f in ${WRKSRC}/docs/cables/*.txt; do \
		${INSTALL_DATA} $$f ${DESTDIR}${NUT_DOCDIR}/cables/; \
	done

# nut-scanner needs libltdl, but this is not documented
.include "../../devel/libltdl/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"

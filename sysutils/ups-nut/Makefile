# $NetBSD: Makefile,v 1.84 2026/05/03 16:39:13 gdt Exp $

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

# nut looks aggressively for asciidoc in a way that is hard to turn off,
# and builds html docs.   asciidoc isn't that big, so just depend on it.
TOOL_DEPENDS+=		asciidoc-[0-9]*:../../textproc/asciidoc

CONFIGURE_ARGS+=	--with-drvpath=${NUT_DRVDIR:Q}
CONFIGURE_ARGS+=	--with-pidpath=${NUT_RUNDIR:Q}
CONFIGURE_ARGS+=	--with-altpidpath=${NUT_RUNDIR:Q}

# nut, bizarrely, does not install headers by default
CONFIGURE_ARGS+=	--with-dev

# Auto-enables if prereqs (not documented) are present.  Unclear
# usefulness, so until rationale to enable (and patch), disable.
CONFIGURE_ARGS+=	--disable-extapi-enphase

CONFIGURE_ARGS+=	--without-snmp		# provided by sysutils/ups-nut-snmp
CONFIGURE_ARGS+=	--without-usb		# provided by sysutils/ups-nut-usb
CONFIGURE_ARGS+=	--without-nut_monitor	# not yet packaged

# Disable python2 to workaround
# https://github.com/networkupstools/nut/issues/1792 which upstream
# declines to fix.
CONFIGURE_ARGS+=	--without-python2

PKG_GROUPS_VARS+=	NUT_GROUP
PKG_USERS_VARS+=	NUT_USER
BUILD_DEFS+=		NUT_RUNDIR NUT_STATEDIR VARBASE

FILES_SUBST+=		NUT_CONFDIR=${NUT_CONFDIR:Q}
FILES_SUBST+=		NUT_STATEDIR=${NUT_STATEDIR:Q}

PKG_USERS=		${NUT_USER}:${NUT_GROUP}
PKG_GROUPS=		${NUT_GROUP}
PKG_GECOS.${NUT_USER}=	Network UPS Tools
# \todo Remove or justify.
PKG_HOME.${NUT_USER}=	${NUT_STATEDIR}
# \todo Remove or justify.
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
# \todo Explain why this is 770 instead of 755.
OWN_DIRS_PERMS=		${NUT_STATEDIR} ${NUT_USER} ${NUT_GROUP} 0770

INSTALLATION_DIRS+=	${NUT_EGDIR}
INSTALLATION_DIRS+=	${NUT_DOCDIR} ${NUT_DOCDIR}/cables ${NUT_DOCDIR}/detailed
# \todo Drop, after understanding why it is here.
INSTALLATION_DIRS+=	${NUT_DOCDIR}/drivers

CHECK_INTERPRETER_SKIP+=	share/nut/solaris-init/nut

post-install:
	for f in AUTHORS COPYING ChangeLog NEWS.adoc README.adoc UPGRADING.adoc; do \
		${INSTALL_DATA} ${WRKSRC}/$$f ${DESTDIR}${NUT_DOCDIR}; \
	done
	for f in ${WRKSRC}/docs/cables/*.txt; do \
		${INSTALL_DATA} $$f ${DESTDIR}${NUT_DOCDIR}/cables; \
	done
	for f in ${WRKSRC}/docs/*.txt; do \
		${INSTALL_DATA} $$f ${DESTDIR}${NUT_DOCDIR}/detailed; \
	done

TEST_TARGET=	check

# nut-scanner needs libltdl, but this is not documented
.include "../../devel/libltdl/buildlink3.mk"
.if !empty(PKG_OPTIONS:Mpython)
.include "../../lang/python/extension.mk"
.endif
.include "../../mk/bsd.pkg.mk"

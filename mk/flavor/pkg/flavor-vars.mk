# $NetBSD: flavor-vars.mk,v 1.15 2010/02/19 14:27:36 joerg Exp $
#
# This Makefile fragment is included indirectly by bsd.prefs.mk and
# defines some variables which must be defined earlier than where
# flavor.mk is included.
#

PKGSRC_MESSAGE_RECIPIENTS?=	# empty

.if !empty(PKGSRC_MESSAGE_RECIPIENTS)
USE_TOOLS+=	mail
.endif

.if defined(PKG_PRESERVE)
USE_TOOLS+=	date
.endif

# This is the package database directory for the default view.
PKG_DBDIR?=		/var/db/pkg

# _PKG_DBDIR is the actual packages database directory where we register
# packages.
#
.if ${PKG_INSTALLATION_TYPE} == "overwrite"
_PKG_DBDIR=		${_CROSS_DESTDIR}${PKG_DBDIR}
.elif ${PKG_INSTALLATION_TYPE} == "pkgviews"
_PKG_DBDIR=		${_CROSS_DESTDIR}${DEPOTBASE}
.endif

PKG_ADD_CMD?=		${PKG_TOOLS_BIN}/pkg_add
PKG_ADMIN_CMD?=		${PKG_TOOLS_BIN}/pkg_admin
PKG_CREATE_CMD?=	${PKG_TOOLS_BIN}/pkg_create
PKG_DELETE_CMD?=	${PKG_TOOLS_BIN}/pkg_delete
PKG_INFO_CMD?=		${PKG_TOOLS_BIN}/pkg_info
PKG_VIEW_CMD?=		${PKG_TOOLS_BIN}/pkg_view
LINKFARM_CMD?=		${PKG_TOOLS_BIN}/linkfarm

# Latest versions of tools required for correct pkgsrc operation.
.if make(replace) && ${_USE_DESTDIR} != "no"
PKGTOOLS_REQD=		20100130
.else
PKGTOOLS_REQD=		20090528
.endif

.if !defined(PKGTOOLS_VERSION)
PKGTOOLS_VERSION!=	${PKG_INFO_CMD} -V 2>/dev/null || echo 20010302
MAKEFLAGS+=		PKGTOOLS_VERSION=${PKGTOOLS_VERSION}
.endif

# Check that we are using up-to-date pkg_* tools with this file.
.if !defined(NO_PKGTOOLS_REQD_CHECK) && ${PKGTOOLS_VERSION} < ${PKGTOOLS_REQD}
BOOTSTRAP_DEPENDS+=	pkg_install>=${PKGTOOLS_REQD}:../../pkgtools/pkg_install
_PKG_INSTALL_DEPENDS=	yes
.endif

AUDIT_PACKAGES?=	${PKG_ADMIN}
_AUDIT_PACKAGES_CMD?=	audit-pkg
_EXTRACT_PKGVULNDIR=	${PKG_ADMIN} config-var PKGVULNDIR
DOWNLOAD_VULN_LIST?=	${PKG_ADMIN} fetch-pkg-vulnerabilities
_AUDIT_CONFIG_FILE=	pkg_install.conf
_AUDIT_CONFIG_OPTION=	IGNORE_URL

# The binary pkg_install tools all need to consistently to refer to the
# correct package database directory.
#
PKGTOOLS_ARGS?=		-K ${_PKG_DBDIR}

# Views are rooted in ${LOCALBASE}, all packages are depoted in
# ${DEPOTBASE}, and the package database directory for the default view
# is in ${PKG_DBDIR}.
#
PKG_VIEW_ARGS?=	-W ${LOCALBASE} -d ${DEPOTBASE} -k ${PKG_DBDIR}

PKG_ADD?=	${PKG_ADD_CMD} ${PKGTOOLS_ARGS}
PKG_ADMIN?=	${PKG_ADMIN_CMD} ${PKGTOOLS_ARGS}
PKG_CREATE?=	${PKG_CREATE_CMD} ${PKGTOOLS_ARGS}
PKG_DELETE?=	${PKG_DELETE_CMD} ${PKGTOOLS_ARGS}
PKG_INFO?=	${PKG_INFO_CMD} ${PKGTOOLS_ARGS}
PKG_VIEW?=	${PKG_VIEW_CMD} ${PKG_VIEW_ARGS}
LINKFARM?=	${LINKFARM_CMD}

# "${_PKG_BEST_EXISTS} pkgpattern" prints out the name of the installed
# package that best matches pkgpattern.  Use this instead of
# "${PKG_INFO} -e pkgpattern" if the latter would return more than one
# package name.
#
_PKG_BEST_EXISTS?=	${PKG_INFO} -E

# XXX Leave this here until all uses of this have been purged from the
# XXX public parts of pkgsrc.
# XXX
PKG_BEST_EXISTS=	${_PKG_BEST_EXISTS}

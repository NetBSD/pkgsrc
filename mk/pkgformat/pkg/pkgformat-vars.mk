# $NetBSD: pkgformat-vars.mk,v 1.8 2020/01/12 23:38:42 joerg Exp $
#
# This Makefile fragment is included indirectly by bsd.prefs.mk and
# defines some variables which must be defined earlier than where
# pkgformat.mk is included.
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
_PKG_DBDIR=		${_CROSS_DESTDIR}${PKG_DBDIR}
_HOST_PKG_DBDIR=	${HOST_PKG_DBDIR:U${PKG_DBDIR}}

PKG_ADD_CMD?=		${PKG_TOOLS_BIN}/pkg_add
PKG_ADMIN_CMD?=		${PKG_TOOLS_BIN}/pkg_admin
PKG_CREATE_CMD?=	${PKG_TOOLS_BIN}/pkg_create
PKG_DELETE_CMD?=	${PKG_TOOLS_BIN}/pkg_delete
PKG_INFO_CMD?=		${PKG_TOOLS_BIN}/pkg_info
LINKFARM_CMD?=		${PKG_TOOLS_BIN}/linkfarm

# Latest versions of tools required for correct pkgsrc operation.
.if !empty(USE_PKG_ADMIN_DIGEST:M[Yy][Ee][Ss])
PKGTOOLS_REQD=		20191008
.else
PKGTOOLS_REQD=		20100914
.endif
# Latest version of pkg_install required to extract packages
PKGTOOLS_VERSION_REQD=	20091115

# Environment used when invoking package tools.  This is used to pass
# environment variables to the package install and deinstall scripts.
#
PKGTOOLS_ENV?=		# empty

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
HOST_PKGTOOLS_ARGS?=	-K ${_HOST_PKG_DBDIR}

PKG_ADD?=	${PKG_ADD_CMD} ${PKGTOOLS_ARGS}
PKG_ADMIN?=	${PKG_ADMIN_CMD} ${PKGTOOLS_ARGS}
PKG_CREATE?=	${PKG_CREATE_CMD} ${PKGTOOLS_ARGS}
PKG_DELETE?=	${PKG_DELETE_CMD} ${PKGTOOLS_ARGS}
PKG_INFO?=	${PKG_INFO_CMD} ${PKGTOOLS_ARGS}
LINKFARM?=	${LINKFARM_CMD}

HOST_PKG_ADD?=		${PKG_ADD_CMD} ${HOST_PKGTOOLS_ARGS}
HOST_PKG_ADMIN?=	${PKG_ADMIN_CMD} ${HOST_PKGTOOLS_ARGS}
HOST_PKG_CREATE?=	${PKG_CREATE_CMD} ${HOST_PKGTOOLS_ARGS}
HOST_PKG_DELETE?=	${PKG_DELETE_CMD} ${HOST_PKGTOOLS_ARGS}
HOST_PKG_INFO?=		${PKG_INFO_CMD} ${HOST_PKGTOOLS_ARGS}
HOST_LINKFARM?=		${LINKFARM_CMD}

# "${_PKG_BEST_EXISTS} pkgpattern" prints out the name of the installed
# package that best matches pkgpattern.  Use this instead of
# "${PKG_INFO} -e pkgpattern" if the latter would return more than one
# package name.
#
_PKG_BEST_EXISTS?=	${PKG_INFO} -E
_HOST_PKG_BEST_EXISTS?=	${HOST_PKG_INFO} -E

# XXX Leave this here until all uses of this have been purged from the
# XXX public parts of pkgsrc.
# XXX
PKG_BEST_EXISTS=	${_PKG_BEST_EXISTS}

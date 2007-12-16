# $NetBSD: flavor-vars.mk,v 1.5 2007/12/16 01:49:08 adrianp Exp $
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

.if !defined(PKGTOOLS_VERSION)
PKGTOOLS_VERSION!=	${PKG_INFO_CMD} -V 2>/dev/null || echo 20010302
MAKEFLAGS+=		PKGTOOLS_VERSION=${PKGTOOLS_VERSION}
.endif

# audit-packages logic for its location depends on a variety of factors
# including OS, pkg_install version and NetBSD version.  The following
# should pick the correct version to run.
#
.if defined(OPSYS) && ${OPSYS} != "NetBSD"
AP?=	${PKG_TOOLS_BIN}/audit-packages
.else
.	if exists(${LOCALBASE}/sbin/audit-packages)
AP?=		${LOCALBASE}/sbin/audit-packages
.	else
.		if exists(/usr/sbin/audit-packages)
AP?=			/usr/sbin/audit-packages
.		else
AP?=			audit-packages
.		endif
.	endif
.endif

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
_PKG_BEST_EXISTS?=	${PKG_ADMIN} -b -d ${_PKG_DBDIR} -S lsbest

# XXX Leave this here until all uses of this have been purged from the
# XXX public parts of pkgsrc.
# XXX
PKG_BEST_EXISTS=	${_PKG_BEST_EXISTS}

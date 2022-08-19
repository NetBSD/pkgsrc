# $NetBSD: desktopdb.mk,v 1.6 2022/08/19 22:05:10 abs Exp $
#
# This Makefile fragment is intended to be included by packages that install
# desktop entries.  It takes care of registering them in the global database
# if desktop-file-utils is installed. It does not add a dependency.

.if !defined(DESKTOP_FILE_UTILS_MIMEDB_MK)
DESKTOP_FILE_UTILS_MIMEDB_MK=	# defined

.include "../../mk/bsd.prefs.mk"

INSTALL_TEMPLATES+=	${.CURDIR}/../../sysutils/desktop-file-utils/files/install.tmpl
DEINSTALL_TEMPLATES+=	${.CURDIR}/../../sysutils/desktop-file-utils/files/install.tmpl

FILES_SUBST+=		APPLICATIONS_PATH="${BUILDLINK_PREFIX.desktop-file-utils}/share/applications"
FILES_SUBST+=		UPDATE_DESKTOPDB="${BUILDLINK_PREFIX.desktop-file-utils}/bin/update-desktop-database"

PRINT_PLIST_AWK+=	/^share\/applications\/mimeinfo.cache$$/ { next }

.endif	# DESKTOP_FILE_UTILS_MIMEDB_MK

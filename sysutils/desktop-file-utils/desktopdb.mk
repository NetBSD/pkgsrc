# $NetBSD: desktopdb.mk,v 1.1.1.1 2004/09/21 17:03:54 jmmv Exp $
#
# This Makefile fragment is intended to be included by packages that install
# desktop entries.  It takes care of registering them in the global database.
#

.if !defined(DESKTOP_FILE_UTILS_MIMEDB_MK)
DESKTOP_FILE_UTILS_MIMEDB_MK=	# defined

. include "../../mk/bsd.prefs.mk"

USE_PKGINSTALL=		YES
INSTALL_EXTRA_TMPL+=	${.CURDIR}/../../sysutils/desktop-file-utils/files/install.tmpl
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/../../sysutils/desktop-file-utils/files/install.tmpl

FILES_SUBST+=		APPLICATIONS_PATH="${BUILDLINK_PREFIX.desktop-file-utils}/share/applications"
FILES_SUBST+=		UPDATE_DESKTOPDB="${BUILDLINK_PREFIX.desktop-file-utils}/bin/update-desktop-database"

PRINT_PLIST_AWK+=	/^share\/applications\/mimeinfo.cache$$/ { next }

.if !defined(NO_BUILDLINK) && !empty(USE_BUILDLINK3:M[yY][eE][sS])
.  include "../../sysutils/desktop-file-utils/buildlink3.mk"
.endif

.endif	# DESKTOP_FILE_UTILS_MIMEDB_MK

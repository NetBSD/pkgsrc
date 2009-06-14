# $NetBSD: mimedb.mk,v 1.6 2009/06/14 22:57:59 joerg Exp $
#
# This Makefile fragment is intended to be included by packages that install
# mime customization files.  It takes care of registering them in the global
# mime database.
#

.if !defined(SHARED_MIME_INFO_MIMEDB_MK)
SHARED_MIME_INFO_MIMEDB_MK=	# defined

.include "../../mk/bsd.prefs.mk"

INSTALL_TEMPLATES+=	${.CURDIR}/../../databases/shared-mime-info/files/install.tmpl
DEINSTALL_TEMPLATES+=	${.CURDIR}/../../databases/shared-mime-info/files/install.tmpl

FILES_SUBST+=		MIMEDB_PATH="${BUILDLINK_PREFIX.shared-mime-info}/share/mime"
FILES_SUBST+=		UPDATE_MIMEDB="${BUILDLINK_PREFIX.shared-mime-info}/bin/update-mime-database"

PRINT_PLIST_AWK+=	/^share\/mime\/packages/ { print; next; }
PRINT_PLIST_AWK+=	/^share\/mime\// { next; }

.include "../../databases/shared-mime-info/buildlink3.mk"

.endif	# SHARED_MIME_INFO_MIMEDB_MK

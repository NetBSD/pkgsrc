# $NetBSD: mimedb.mk,v 1.2 2005/03/24 22:42:58 jlam Exp $
#
# This Makefile fragment is intended to be included by packages that install
# mime customization files.  It takes care of registering them in the global
# mime database.
#

.if !defined(SHARED_MIME_INFO_MIMEDB_MK)
SHARED_MIME_INFO_MIMEDB_MK=	# defined

.include "../../mk/bsd.prefs.mk"

USE_PKGINSTALL=		YES
INSTALL_EXTRA_TMPL+=	${.CURDIR}/../../databases/shared-mime-info/files/install.tmpl
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/../../databases/shared-mime-info/files/install.tmpl

FILES_SUBST+=		MIMEDB_PATH="${BUILDLINK_PREFIX.shared-mime-info}/share/mime"
FILES_SUBST+=		UPDATE_MIMEDB="${BUILDLINK_PREFIX.shared-mime-info}/bin/update-mime-database"

PRINT_PLIST_AWK+=	/^share\/mime\/packages/ { print; next; }
PRINT_PLIST_AWK+=	/^share\/mime\// { next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/mime\/packages$$/ \
				{ print "@comment in shared-mime-info: " $$0; \
				  next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/mime\// { next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/mime$$/ { next; }

.include "../../databases/shared-mime-info/buildlink3.mk"

.endif	# SHARED_MIME_INFO_MIMEDB_MK

# $NetBSD: buildlink2.mk,v 1.1.1.1 2002/10/30 06:44:59 rh Exp $
#
# This Makefile fragment is included by packages that use gnome-db.
#
# This file was created automatically using createbuildlink 2.2.
#

.if !defined(GNOME_DB_BUILDLINK2_MK)
GNOME_DB_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gnome-db
BUILDLINK_DEPENDS.gnome-db?=		gnome-db>=0.8.192
BUILDLINK_PKGSRCDIR.gnome-db?=		../../databases/gnome-db

EVAL_PREFIX+=	BUILDLINK_PREFIX.gnome-db=gnome-db
BUILDLINK_PREFIX.gnome-db_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gnome-db+=	lib/bonobo/servers/GNOME_Database_UIComponents.server

.include "../../databases/libgnomedb/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"

BUILDLINK_TARGETS+=	gnome-db-buildlink

gnome-db-buildlink: _BUILDLINK_USE

.endif	# GNOME_DB_BUILDLINK2_MK

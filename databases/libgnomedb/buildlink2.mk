# $NetBSD: buildlink2.mk,v 1.7 2003/11/12 01:31:47 salo Exp $
#
# This Makefile fragment is included by packages that use libgnomedb.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(LIBGNOMEDB_BUILDLINK2_MK)
LIBGNOMEDB_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libgnomedb
BUILDLINK_DEPENDS.libgnomedb?=		libgnomedb>=1.0.0nb1
BUILDLINK_PKGSRCDIR.libgnomedb?=		../../databases/libgnomedb

EVAL_PREFIX+=	BUILDLINK_PREFIX.libgnomedb=libgnomedb
BUILDLINK_PREFIX.libgnomedb_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libgnomedb+=	include/libgnomedb/*
BUILDLINK_FILES.libgnomedb+=	lib/bonobo/monikers/libmoniker_database.*
BUILDLINK_FILES.libgnomedb+=	lib/bonobo/servers/GNOME_Database_Components.server
BUILDLINK_FILES.libgnomedb+=	lib/bonobo/servers/GNOME_Database_Monikers.server
BUILDLINK_FILES.libgnomedb+=	lib/libglade/2.0/libgnomedb.*
BUILDLINK_FILES.libgnomedb+=	lib/libgnomedb-2.*
BUILDLINK_FILES.libgnomedb+=	lib/pkgconfig/libgnomedb.pc

.include "../../databases/libgda/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/bonobo-activation/buildlink2.mk"
.include "../../devel/libbonoboui/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

BUILDLINK_TARGETS+=	libgnomedb-buildlink

libgnomedb-buildlink: _BUILDLINK_USE

.endif	# LIBGNOMEDB_BUILDLINK2_MK

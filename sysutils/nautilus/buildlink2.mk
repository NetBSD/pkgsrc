# $NetBSD: buildlink2.mk,v 1.3 2003/11/12 01:31:51 salo Exp $
#
# This Makefile fragment is included by packages that use nautilus.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(NAUTILUS_BUILDLINK2_MK)
NAUTILUS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			nautilus
BUILDLINK_DEPENDS.nautilus?=		nautilus>=2.2.3.1nb6
BUILDLINK_PKGSRCDIR.nautilus?=		../../sysutils/nautilus

EVAL_PREFIX+=	BUILDLINK_PREFIX.nautilus=nautilus
BUILDLINK_PREFIX.nautilus_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.nautilus+=	include/libnautilus/*
BUILDLINK_FILES.nautilus+=	lib/bonobo/libnautilus-emblem-view.*
BUILDLINK_FILES.nautilus+=	lib/bonobo/libnautilus-history-view.*
BUILDLINK_FILES.nautilus+=	lib/bonobo/libnautilus-image-properties-view.*
BUILDLINK_FILES.nautilus+=	lib/bonobo/libnautilus-notes-view.*
BUILDLINK_FILES.nautilus+=	lib/bonobo/libnautilus-tree-view.*
BUILDLINK_FILES.nautilus+=	lib/bonobo/servers/Nautilus_ComponentAdapterFactory_std.server
BUILDLINK_FILES.nautilus+=	lib/bonobo/servers/Nautilus_Control_throbber.server
BUILDLINK_FILES.nautilus+=	lib/bonobo/servers/Nautilus_View_emblem.server
BUILDLINK_FILES.nautilus+=	lib/bonobo/servers/Nautilus_View_history.server
BUILDLINK_FILES.nautilus+=	lib/bonobo/servers/Nautilus_View_image_properties.server
BUILDLINK_FILES.nautilus+=	lib/bonobo/servers/Nautilus_View_notes.server
BUILDLINK_FILES.nautilus+=	lib/bonobo/servers/Nautilus_View_text.server
BUILDLINK_FILES.nautilus+=	lib/bonobo/servers/Nautilus_View_tree.server
BUILDLINK_FILES.nautilus+=	lib/bonobo/servers/Nautilus_shell.server
BUILDLINK_FILES.nautilus+=	lib/libnautilus-adapter.*
BUILDLINK_FILES.nautilus+=	lib/libnautilus-private.*
BUILDLINK_FILES.nautilus+=	lib/libnautilus.*
BUILDLINK_FILES.nautilus+=	lib/pkgconfig/libnautilus.pc

.include "../../devel/eel2/buildlink2.mk"
.include "../../graphics/imlib2/buildlink2.mk"
.include "../../graphics/librsvg2/buildlink2.mk"
.include "../../sysutils/fam/buildlink2.mk"
.include "../../textproc/intltool/buildlink2.mk"
.include "../../x11/gnome-desktop/buildlink2.mk"

BUILDLINK_TARGETS+=	nautilus-buildlink

nautilus-buildlink: _BUILDLINK_USE

.endif	# NAUTILUS_BUILDLINK2_MK

# $NetBSD: buildlink2.mk,v 1.12 2004/02/14 00:23:34 jmmv Exp $
#
# This Makefile fragment is included by packages that use nautilus.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(NAUTILUS_BUILDLINK2_MK)
NAUTILUS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			nautilus
BUILDLINK_DEPENDS.nautilus?=		nautilus>=2.4.2nb4
BUILDLINK_PKGSRCDIR.nautilus?=		../../sysutils/nautilus

EVAL_PREFIX+=	BUILDLINK_PREFIX.nautilus=nautilus
BUILDLINK_PREFIX.nautilus_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.nautilus+=	include/libnautilus/*
BUILDLINK_FILES.nautilus+=	lib/bonobo/libnautilus-emblem-view.*
BUILDLINK_FILES.nautilus+=	lib/bonobo/libnautilus-history-view.*
BUILDLINK_FILES.nautilus+=	lib/bonobo/libnautilus-image-properties-view.*
BUILDLINK_FILES.nautilus+=	lib/bonobo/libnautilus-notes-view.*
BUILDLINK_FILES.nautilus+=	lib/bonobo/libnautilus-tree-view.*
BUILDLINK_FILES.nautilus+=	lib/libnautilus-adapter.*
BUILDLINK_FILES.nautilus+=	lib/libnautilus-private.*
BUILDLINK_FILES.nautilus+=	lib/libnautilus.*

BUILDLINK_DEPENDS.esound=	esound>=0.2.27

.include "../../audio/esound/buildlink2.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/eel2/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/libbonobo/buildlink2.mk"
.include "../../devel/libbonoboui/buildlink2.mk"
.include "../../devel/libgnome/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/libgsf/buildlink2.mk"
.include "../../devel/pango/buildlink2.mk"
.include "../../graphics/libart2/buildlink2.mk"
.include "../../graphics/librsvg2/buildlink2.mk"
.include "../../net/ORBit2/buildlink2.mk"
.include "../../sysutils/gnome-vfs2/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../x11/gnome-desktop/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../x11/startup-notification/buildlink2.mk"

BUILDLINK_TARGETS+=	nautilus-buildlink

nautilus-buildlink: _BUILDLINK_USE

.endif	# NAUTILUS_BUILDLINK2_MK

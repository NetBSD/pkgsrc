# $NetBSD: buildlink2.mk,v 1.5 2003/11/12 01:31:47 salo Exp $
#
# This Makefile fragment is included by packages that use gnome-media.
#
# This file was created automatically using createbuildlink 2.4.
#

.if !defined(GNOME_MEDIA_BUILDLINK2_MK)
GNOME_MEDIA_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gnome-media
BUILDLINK_DEPENDS.gnome-media?=		gnome-media>=2.2.1.1nb3
BUILDLINK_PKGSRCDIR.gnome-media?=		../../audio/gnome2-media

EVAL_PREFIX+=	BUILDLINK_PREFIX.gnome-media=gnome-media
BUILDLINK_PREFIX.gnome-media_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gnome-media+=	include/cddb-slave2/*.h
BUILDLINK_FILES.gnome-media+=	lib/bonobo/servers/GNOME_Media_CDDBSlave2.server
BUILDLINK_FILES.gnome-media+=	lib/libcddb-slave2.*

.include "../../audio/esound/buildlink2.mk"
.include "../../misc/gst-plugins/buildlink2.mk"
.include "../../misc/gstreamer/buildlink2.mk"
.include "../../devel/GConf2-ui/buildlink2.mk"
.include "../../devel/gail/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../x11/gnome-desktop/buildlink2.mk"

BUILDLINK_TARGETS+=	gnome-media-buildlink

gnome-media-buildlink: _BUILDLINK_USE

.endif	# GNOME_MEDIA_BUILDLINK2_MK

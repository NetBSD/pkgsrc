# $NetBSD: buildlink2.mk,v 1.1.1.1 2002/09/05 16:05:33 wiz Exp $

.if !defined(GNOME_MIME_DATA_BUILDLINK2_MK)
GNOME_MIME_DATA_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gnome-mime-data
BUILDLINK_DEPENDS.gnome-mime-data?=	gnome-mime-data>=1.0.7
BUILDLINK_PKGSRCDIR.gnome-mime-data?=	../../databases/gnome-mime-data
#BUILDLINK_DEPMETHOD.gnome-mime-data?=	build

EVAL_PREFIX+=	BUILDLINK_PREFIX.gnome-mime-data=gnome-mime-data
BUILDLINK_PREFIX.gnome-mime-data_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gnome-mime-data+=	lib/pkgconfig/gnome-mime-data-2.0.pc

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"

BUILDLINK_TARGETS+=	gnome-mime-data-buildlink

gnome-mime-data-buildlink: _BUILDLINK_USE

.endif	# GNOME_MIME_DATA_BUILDLINK2_MK

# $NetBSD: buildlink2.mk,v 1.11 2004/02/13 23:29:17 jmmv Exp $
#
# This Makefile fragment is included by packages that use eel2.
#
# This file was created automatically using createbuildlink 2.2.
#

.if !defined(EEL2_BUILDLINK2_MK)
EEL2_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			eel2
BUILDLINK_DEPENDS.eel2?=		eel2>=2.4.1nb2
BUILDLINK_PKGSRCDIR.eel2?=		../../devel/eel2

EVAL_PREFIX+=	BUILDLINK_PREFIX.eel2=eel2
BUILDLINK_PREFIX.eel2_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.eel2+=	include/eel-2/eel/*.h
BUILDLINK_FILES.eel2+=	lib/libeel-2.*

.include "../../devel/GConf2/buildlink2.mk"
.include "../../devel/gail/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../devel/libgnome/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../graphics/libart2/buildlink2.mk"
.include "../../sysutils/gnome-vfs2/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

BUILDLINK_TARGETS+=	eel2-buildlink

eel2-buildlink: _BUILDLINK_USE

.endif	# EEL2_BUILDLINK2_MK

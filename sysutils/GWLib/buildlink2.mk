# $NetBSD: buildlink2.mk,v 1.1.1.1 2002/09/28 02:19:03 rh Exp $
#
# This Makefile fragment is included by packages that use GWLib.
#
# This file was created automatically using createbuildlink 2.1.
#

.if !defined(GWLIB_BUILDLINK2_MK)
GWLIB_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			GWLib
BUILDLINK_DEPENDS.GWLib?=		GWLib>=0.4
BUILDLINK_PKGSRCDIR.GWLib?=		../../sysutils/GWLib

EVAL_PREFIX+=	BUILDLINK_PREFIX.GWLib=GWLib
BUILDLINK_PREFIX.GWLib_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.GWLib+=	share/GNUstep/System/Headers/GWorkspace/ContentViewersProtocol.h
BUILDLINK_FILES.GWLib+=	share/GNUstep/System/Headers/GWorkspace/GWFunctions.h
BUILDLINK_FILES.GWLib+=	share/GNUstep/System/Headers/GWorkspace/GWNotifications.h
BUILDLINK_FILES.GWLib+=	share/GNUstep/System/Headers/GWorkspace/GWProtocol.h
BUILDLINK_FILES.GWLib+=	share/GNUstep/System/Headers/GWorkspace/IconViewsProtocol.h
BUILDLINK_FILES.GWLib+=	share/GNUstep/System/Headers/GWorkspace/InspectorsProtocol.h
BUILDLINK_FILES.GWLib+=	share/GNUstep/System/Headers/GWorkspace/ViewersProtocol.h
BUILDLINK_FILES.GWLib+=	share/GNUstep/System/Libraries/${GNUSTEP_HOST_CPU}/${LOWER_OPSYS}${APPEND_ELF}/gnu-gnu-gnu/libGWorkspace.*

.include "../../x11/gnustep-back/buildlink2.mk"

BUILDLINK_TARGETS+=	GWLib-buildlink

GWLib-buildlink: _BUILDLINK_USE

.endif	# GWLIB_BUILDLINK2_MK

# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/01/11 02:56:25 rh Exp $
#
# This Makefile fragment is included by packages that use gnome-pilot.
#
# This file was created automatically using createbuildlink 2.4.
#

.if !defined(GNOME_PILOT_BUILDLINK2_MK)
GNOME_PILOT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gnome-pilot
BUILDLINK_DEPENDS.gnome-pilot?=		gnome-pilot>=0.1.71
BUILDLINK_PKGSRCDIR.gnome-pilot?=		../../comms/gnome-pilot

EVAL_PREFIX+=	BUILDLINK_PREFIX.gnome-pilot=gnome-pilot
BUILDLINK_PREFIX.gnome-pilot_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.gnome-pilot+=	include/gpilotd/*.h
BUILDLINK_FILES.gnome-pilot+=	include/libgpilotdCM/*.h
BUILDLINK_FILES.gnome-pilot+=	lib/gnome-pilot/conduits/libbackup_conduit.*
BUILDLINK_FILES.gnome-pilot+=	lib/gnome-pilot/conduits/libfile_conduit.*
BUILDLINK_FILES.gnome-pilot+=	lib/gnome-pilot/conduits/libtest_conduit.*
BUILDLINK_FILES.gnome-pilot+=	lib/gpilotConf.sh
BUILDLINK_FILES.gnome-pilot+=	lib/libgpilotd.*
BUILDLINK_FILES.gnome-pilot+=	lib/libgpilotdcm.*
BUILDLINK_FILES.gnome-pilot+=	lib/libgpilotdconduit.*

.include "../../comms/pilot-link-libs/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libglade/buildlink2.mk"
.include "../../textproc/libxml/buildlink2.mk"
.include "../../x11/gnome-core/buildlink2.mk"

BUILDLINK_TARGETS+=	gnome-pilot-buildlink

gnome-pilot-buildlink: _BUILDLINK_USE

.endif	# GNOME_PILOT_BUILDLINK2_MK

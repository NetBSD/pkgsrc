# $NetBSD: buildlink3.mk,v 1.3 2018/01/07 13:04:25 rillig Exp $

#
# For linking use LDFLAGS.vdpau variable
#

# Check whether VDPAU is available on this platform
.include "../../multimedia/libvdpau/available.mk"
.if ${VDPAU_AVAILABLE} == "yes"

BUILDLINK_TREE+=	libvdpau

.  if !defined(LIBVDPAU_BUILDLINK3_MK)
LIBVDPAU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libvdpau+=	libvdpau>=0.3
BUILDLINK_PKGSRCDIR.libvdpau?=		../../multimedia/libvdpau

.include "../../x11/libX11/buildlink3.mk"
.  endif	# LIBVDPAU_BUILDLINK3_MK

BUILDLINK_TREE+=	-libvdpau

LDFLAGS.vdpau=		-lvdpau

.endif # Linux, FreeBSD, SunOS...

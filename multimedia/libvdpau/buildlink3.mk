# $NetBSD: buildlink3.mk,v 1.2 2010/09/01 20:54:09 wiz Exp $

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
BUILDLINK_PKGSRCDIR.libvdpau?=	../../multimedia/libvdpau

.include "../../x11/libX11/buildlink3.mk"
.  endif	# LIBVDPAU_BUILDLINK3_MK

BUILDLINK_TREE+=	-libvdpau

LDFLAGS.vdpau=		-lvdpau

.endif # Linux, FreeBSD, SunOS...

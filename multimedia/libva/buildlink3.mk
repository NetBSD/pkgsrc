# $NetBSD: buildlink3.mk,v 1.4 2018/11/23 08:18:16 ryoon Exp $

.include "../../multimedia/libva/available.mk"
.if ${VAAPI_AVAILABLE} == "yes"

BUILDLINK_TREE+=	libva

.  if !defined(LIBVA_BUILDLINK3_MK)
LIBVA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libva+=	libva>=2.3.0
BUILDLINK_PKGSRCDIR.libva?=	../../multimedia/libva

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"

.  endif	# LIBVA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libva

.endif # VAAPI_AVAILABLE

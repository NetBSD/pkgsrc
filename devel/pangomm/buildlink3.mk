# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:24:26 joerg Exp $

BUILDLINK_TREE+=	pangomm

.if !defined(PANGOMM_BUILDLINK3_MK)
PANGOMM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pangomm+=	pangomm>=2.24.0
BUILDLINK_PKGSRCDIR.pangomm?=	../../devel/pangomm

.include "../../devel/glibmm/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairomm/buildlink3.mk"
.endif # PANGOMM_BUILDLINK3_MK

BUILDLINK_TREE+=	-pangomm

# $NetBSD: buildlink3.mk,v 1.6 2023/11/14 14:01:39 wiz Exp $

BUILDLINK_TREE+=	pangomm2.48

.if !defined(PANGOMM2.48_BUILDLINK3_MK)
PANGOMM2.48_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pangomm2.48+=	pangomm2.48>=2.48.1
BUILDLINK_ABI_DEPENDS.pangomm2.48?=	pangomm2.48>=2.48.2nb4
BUILDLINK_PKGSRCDIR.pangomm2.48?=	../../devel/pangomm2.48

.include "../../devel/glibmm2.68/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairomm1.16/buildlink3.mk"
.endif	# PANGOMM2.48_BUILDLINK3_MK

BUILDLINK_TREE+=	-pangomm2.48

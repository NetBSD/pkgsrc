# $NetBSD: buildlink3.mk,v 1.16 2022/06/28 11:36:10 wiz Exp $

BUILDLINK_TREE+=	eb

.if !defined(EB_BUILDLINK3_MK)
EB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.eb+=		eb>=3.3.2nb1
BUILDLINK_ABI_DEPENDS.eb+=		eb>=4.3nb13
BUILDLINK_PKGSRCDIR.eb?=		../../textproc/eb

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif # EB_BUILDLINK3_MK

BUILDLINK_TREE+=	-eb

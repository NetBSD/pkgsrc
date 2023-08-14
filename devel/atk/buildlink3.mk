# $NetBSD: buildlink3.mk,v 1.23 2023/08/14 05:24:04 wiz Exp $

BUILDLINK_TREE+=	atk

.if !defined(ATK_BUILDLINK3_MK)
ATK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.atk+=	atk>=1.11.4
BUILDLINK_ABI_DEPENDS.atk+=	atk>=2.38.0nb1
BUILDLINK_PKGSRCDIR.atk?=	../../devel/atk

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # ATK_BUILDLINK3_MK

BUILDLINK_TREE+=	-atk

# $NetBSD: buildlink3.mk,v 1.4 2018/01/07 13:04:35 rillig Exp $

BUILDLINK_TREE+=	oniguruma

.if !defined(ONIGURUMA_BUILDLINK3_MK)
ONIGURUMA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.oniguruma+=	oniguruma>=5.9.1
BUILDLINK_PKGSRCDIR.oniguruma?=		../../textproc/oniguruma
.endif # ONIGURUMA_BUILDLINK3_MK

BUILDLINK_TREE+=	-oniguruma

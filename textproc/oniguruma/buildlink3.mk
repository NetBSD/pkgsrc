# $NetBSD: buildlink3.mk,v 1.5 2018/03/22 08:05:25 adam Exp $

BUILDLINK_TREE+=	oniguruma

.if !defined(ONIGURUMA_BUILDLINK3_MK)
ONIGURUMA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.oniguruma+=	oniguruma>=6.8.1
BUILDLINK_PKGSRCDIR.oniguruma?=		../../textproc/oniguruma
.endif # ONIGURUMA_BUILDLINK3_MK

BUILDLINK_TREE+=	-oniguruma

# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:25:31 joerg Exp $

BUILDLINK_TREE+=	oniguruma

.if !defined(ONIGURUMA_BUILDLINK3_MK)
ONIGURUMA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.oniguruma+=	oniguruma>=5.9.1
BUILDLINK_PKGSRCDIR.oniguruma?=	../../textproc/oniguruma
.endif # ONIGURUMA_BUILDLINK3_MK

BUILDLINK_TREE+=	-oniguruma

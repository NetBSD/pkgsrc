# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:25:08 joerg Exp $

BUILDLINK_TREE+=	freewais-sf

.if !defined(FREEWAIS_SF_BUILDLINK3_MK)
FREEWAIS_SF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.freewais-sf+=	freewais-sf>=2.2.12
BUILDLINK_ABI_DEPENDS.freewais-sf+=	freewais-sf>=2.2.12nb2
BUILDLINK_PKGSRCDIR.freewais-sf?=	../../net/freewais-sf
.endif # FREEWAIS_SF_BUILDLINK3_MK

BUILDLINK_TREE+=	-freewais-sf

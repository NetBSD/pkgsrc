# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:24:48 joerg Exp $

BUILDLINK_TREE+=	elk

.if !defined(ELK_BUILDLINK3_MK)
ELK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.elk+=	elk>=3.99.6
BUILDLINK_PKGSRCDIR.elk?=	../../lang/elk
.endif # ELK_BUILDLINK3_MK

BUILDLINK_TREE+=	-elk

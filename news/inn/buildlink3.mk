# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:25:13 joerg Exp $

BUILDLINK_TREE+=	inn

.if !defined(INN_BUILDLINK3_MK)
INN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.inn+=	inn>=2.3.4
BUILDLINK_PKGSRCDIR.inn?=	../../news/inn
.endif # INN_BUILDLINK3_MK

BUILDLINK_TREE+=	-inn

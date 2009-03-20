# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:21 joerg Exp $

BUILDLINK_TREE+=	librlog

.if !defined(LIBRLOG_BUILDLINK3_MK)
LIBRLOG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.librlog+=	librlog>=1.3.7
BUILDLINK_PKGSRCDIR.librlog?=	../../devel/librlog
.endif # LIBRLOG_BUILDLINK3_MK

BUILDLINK_TREE+=	-librlog

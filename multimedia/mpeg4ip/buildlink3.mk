# $NetBSD: buildlink3.mk,v 1.4 2009/03/20 19:25:05 joerg Exp $

BUILDLINK_TREE+=	mpeg4ip

.if !defined(MPEG4IP_BUILDLINK3_MK)
MPEG4IP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mpeg4ip+=	mpeg4ip>=1.4.1
BUILDLINK_PKGSRCDIR.mpeg4ip?=	../../multimedia/mpeg4ip
.endif # MPEG4IP_BUILDLINK3_MK

BUILDLINK_TREE+=	-mpeg4ip

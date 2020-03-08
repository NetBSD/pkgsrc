# $NetBSD: buildlink3.mk,v 1.2 2020/03/08 16:48:15 wiz Exp $

BUILDLINK_TREE+=	ots

.if !defined(OTS_BUILDLINK3_MK)
OTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ots+=	ots>=0.5.0
BUILDLINK_ABI_DEPENDS.ots?=	ots>=0.5.0nb1
BUILDLINK_PKGSRCDIR.ots?=	../../textproc/ots

.include "../../devel/glib2/buildlink3.mk"
.endif	# OTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ots

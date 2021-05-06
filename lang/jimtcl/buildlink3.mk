# $NetBSD: buildlink3.mk,v 1.1 2021/05/06 10:38:34 tnn Exp $

BUILDLINK_TREE+=	jimtcl

.if !defined(JIMTCL_BUILDLINK3_MK)
JIMTCL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jimtcl+=	jimtcl>=0.80
BUILDLINK_PKGSRCDIR.jimtcl?=	../../lang/jimtcl
.endif	# JIMTCL_BUILDLINK3_MK

BUILDLINK_TREE+=	-jimtcl

# $NetBSD: buildlink3.mk,v 1.2 2021/05/06 15:19:39 tnn Exp $

BUILDLINK_TREE+=	jimtcl

.if !defined(JIMTCL_BUILDLINK3_MK)
JIMTCL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jimtcl+=	jimtcl>=0.80nb1
BUILDLINK_PKGSRCDIR.jimtcl?=	../../lang/jimtcl
.endif	# JIMTCL_BUILDLINK3_MK

BUILDLINK_TREE+=	-jimtcl

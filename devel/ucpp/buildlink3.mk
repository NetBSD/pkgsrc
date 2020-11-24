# $NetBSD: buildlink3.mk,v 1.1 2020/11/24 13:34:34 nia Exp $

BUILDLINK_TREE+=	ucpp

.if !defined(UCPP_BUILDLINK3_MK)
UCPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ucpp+=	ucpp>=1.3.5
BUILDLINK_PKGSRCDIR.ucpp?=	../../devel/ucpp
.endif	# UCPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-ucpp

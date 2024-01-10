# $NetBSD: buildlink3.mk,v 1.3 2024/01/10 08:20:10 tnn Exp $

BUILDLINK_TREE+=	jimtcl

.if !defined(JIMTCL_BUILDLINK3_MK)
JIMTCL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jimtcl+=	jimtcl>=0.80nb1
BUILDLINK_PKGSRCDIR.jimtcl?=	../../lang/jimtcl

.include "../../devel/zlib/buildlink3.mk"
.endif	# JIMTCL_BUILDLINK3_MK

BUILDLINK_TREE+=	-jimtcl

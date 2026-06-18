# $NetBSD: buildlink3.mk,v 1.4 2026/06/18 13:12:35 thorpej Exp $

BUILDLINK_TREE+=	jimtcl

.if !defined(JIMTCL_BUILDLINK3_MK)
JIMTCL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jimtcl+=	jimtcl>=0.83nb1
BUILDLINK_PKGSRCDIR.jimtcl?=	../../lang/jimtcl

.include "../../devel/zlib/buildlink3.mk"
.endif	# JIMTCL_BUILDLINK3_MK

BUILDLINK_TREE+=	-jimtcl

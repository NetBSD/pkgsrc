# $NetBSD: buildlink3.mk,v 1.20 2023/11/12 13:21:09 wiz Exp $

BUILDLINK_TREE+=	pangox-compat

.if !defined(PANGOX_COMPAT_BUILDLINK3_MK)
PANGOX_COMPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pangox-compat+=	pangox-compat>=0.0.1
BUILDLINK_ABI_DEPENDS.pangox-compat?=	pangox-compat>=0.0.2nb13
BUILDLINK_PKGSRCDIR.pangox-compat?=	../../devel/pangox-compat

.include "../../devel/pango/buildlink3.mk"
.endif	# PANGOX_COMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-pangox-compat

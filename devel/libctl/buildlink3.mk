# $NetBSD: buildlink3.mk,v 1.6 2022/10/26 10:31:01 wiz Exp $

BUILDLINK_TREE+=	libctl

.if !defined(LIBCTL_BUILDLINK3_MK)
LIBCTL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libctl+=	libctl>=3.2.2
BUILDLINK_ABI_DEPENDS.libctl?=	libctl>=3.2.2nb5
BUILDLINK_PKGSRCDIR.libctl?=	../../devel/libctl

.include "../../lang/guile20/buildlink3.mk"
.endif	# LIBCTL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libctl

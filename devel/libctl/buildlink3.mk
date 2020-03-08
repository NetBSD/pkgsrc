# $NetBSD: buildlink3.mk,v 1.4 2020/03/08 16:47:36 wiz Exp $

BUILDLINK_TREE+=	libctl

.if !defined(LIBCTL_BUILDLINK3_MK)
LIBCTL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libctl+=	libctl>=3.2.2
BUILDLINK_ABI_DEPENDS.libctl?=	libctl>=3.2.2nb2
BUILDLINK_PKGSRCDIR.libctl?=	../../devel/libctl

.include "../../lang/guile20/buildlink3.mk"
.endif	# LIBCTL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libctl

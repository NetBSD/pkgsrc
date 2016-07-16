# $NetBSD: buildlink3.mk,v 1.2 2016/07/16 20:05:57 wiz Exp $

BUILDLINK_TREE+=	libctl

.if !defined(LIBCTL_BUILDLINK3_MK)
LIBCTL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libctl+=	libctl>=3.2.2
BUILDLINK_PKGSRCDIR.libctl?=	../../devel/libctl

.include "../../lang/guile20/buildlink3.mk"
.endif	# LIBCTL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libctl

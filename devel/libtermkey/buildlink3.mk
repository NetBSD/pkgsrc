# $NetBSD: buildlink3.mk,v 1.1 2022/04/20 17:41:08 nia Exp $

BUILDLINK_TREE+=	libtermkey

.if !defined(LIBTERMKEY_BUILDLINK3_MK)
LIBTERMKEY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtermkey+=	libtermkey>=0.17
BUILDLINK_PKGSRCDIR.libtermkey?=	../../devel/libtermkey

.include "../../devel/unibilium/buildlink3.mk"
.endif	# LIBTERMKEY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtermkey

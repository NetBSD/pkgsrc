# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:25:19 joerg Exp $

BUILDLINK_TREE+=	libksba

.if !defined(LIBKSBA_BUILDLINK3_MK)
LIBKSBA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libksba+=	libksba>=0.4.7nb1
BUILDLINK_ABI_DEPENDS.libksba+=	libksba>=0.4.7nb2
BUILDLINK_PKGSRCDIR.libksba?=	../../security/libksba04
.endif # LIBKSBA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libksba

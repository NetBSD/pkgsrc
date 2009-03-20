# $NetBSD: buildlink3.mk,v 1.14 2009/03/20 19:25:19 joerg Exp $

BUILDLINK_TREE+=	libnasl

.if !defined(LIBNASL_BUILDLINK3_MK)
LIBNASL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnasl+=	libnasl>=2.2.11
BUILDLINK_ABI_DEPENDS.libnasl?=	libnasl>=2.2.11nb1
BUILDLINK_PKGSRCDIR.libnasl?=	../../security/libnasl

.include "../../security/nessus-libraries/buildlink3.mk"
.endif # LIBNASL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libnasl

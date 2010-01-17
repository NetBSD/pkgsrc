# $NetBSD: buildlink3.mk,v 1.15 2010/01/17 12:02:41 wiz Exp $

BUILDLINK_TREE+=	libnasl

.if !defined(LIBNASL_BUILDLINK3_MK)
LIBNASL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnasl+=	libnasl>=2.2.11
BUILDLINK_ABI_DEPENDS.libnasl?=	libnasl>=2.2.11nb2
BUILDLINK_PKGSRCDIR.libnasl?=	../../security/libnasl

.include "../../security/nessus-libraries/buildlink3.mk"
.endif # LIBNASL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libnasl

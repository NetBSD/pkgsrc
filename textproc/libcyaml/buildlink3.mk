# $NetBSD: buildlink3.mk,v 1.2 2021/08/06 14:10:21 nia Exp $

BUILDLINK_TREE+=	libcyaml

.if !defined(LIBCYAML_BUILDLINK3_MK)
LIBCYAML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcyaml+=	libcyaml>=1.1.0
BUILDLINK_ABI_DEPENDS.libcyaml+=	libcyaml>=1.1.0
BUILDLINK_PKGSRCDIR.libcyaml?=		../../wip/libcyaml

.include "../../textproc/libyaml/buildlink3.mk"
.endif # LIBCYAML_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcyaml

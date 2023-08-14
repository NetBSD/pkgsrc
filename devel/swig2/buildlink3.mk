# $NetBSD: buildlink3.mk,v 1.6 2023/08/14 05:24:17 wiz Exp $

BUILDLINK_TREE+=	swig2

.if !defined(SWIG2_BUILDLINK3_MK)
SWIG2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.swig2+=	swig2>=2.0.8
BUILDLINK_ABI_DEPENDS.swig2?=	swig2>=2.0.12nb7
BUILDLINK_PKGSRCDIR.swig2?=	../../devel/swig2

.include "../../devel/pcre/buildlink3.mk"
.endif	# SWIG2_BUILDLINK3_MK

BUILDLINK_TREE+=	-swig2

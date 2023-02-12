# $NetBSD: buildlink3.mk,v 1.1 2023/02/12 10:56:55 tnn Exp $

BUILDLINK_TREE+=	swig4

.if !defined(SWIG4_BUILDLINK3_MK)
SWIG4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.swig4+=	swig4>=4.1.1
BUILDLINK_PKGSRCDIR.swig4?=	../../devel/swig4

.include "../../devel/pcre2/buildlink3.mk"
.endif	# SWIG4_BUILDLINK3_MK

BUILDLINK_TREE+=	-swig4

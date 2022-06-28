# $NetBSD: buildlink3.mk,v 1.2 2022/06/28 11:33:44 wiz Exp $

BUILDLINK_TREE+=	swig3

.if !defined(SWIG3_BUILDLINK3_MK)
SWIG3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.swig3+=	swig3>=3.0.12
BUILDLINK_ABI_DEPENDS.swig3?=	swig3>=3.0.12nb5
BUILDLINK_PKGSRCDIR.swig3?=	../../devel/swig3

.include "../../devel/pcre/buildlink3.mk"
.endif	# SWIG3_BUILDLINK3_MK

BUILDLINK_TREE+=	-swig3

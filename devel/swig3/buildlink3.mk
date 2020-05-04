# $NetBSD: buildlink3.mk,v 1.1 2020/05/04 17:35:52 wiz Exp $

BUILDLINK_TREE+=	swig3

.if !defined(SWIG3_BUILDLINK3_MK)
SWIG3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.swig3+=	swig3>=3.0.12
BUILDLINK_PKGSRCDIR.swig3?=	../../devel/swig3

.include "../../devel/pcre/buildlink3.mk"
.endif	# SWIG3_BUILDLINK3_MK

BUILDLINK_TREE+=	-swig3

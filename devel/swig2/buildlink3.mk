# $NetBSD: buildlink3.mk,v 1.3 2013/06/14 18:41:30 wiz Exp $

BUILDLINK_TREE+=	swig2

.if !defined(SWIG2_BUILDLINK3_MK)
SWIG2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.swig2+=	swig>=2.0.8
BUILDLINK_PKGSRCDIR.swig2?=	../../devel/swig2

.include "../../devel/pcre/buildlink3.mk"
.endif	# SWIG2_BUILDLINK3_MK

BUILDLINK_TREE+=	-swig2

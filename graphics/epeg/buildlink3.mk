# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:24:38 joerg Exp $

BUILDLINK_TREE+=	epeg

.if !defined(EPEG_BUILDLINK3_MK)
EPEG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.epeg+=	epeg>=0.9.0
BUILDLINK_PKGSRCDIR.epeg?=	../../graphics/epeg

.include "../../devel/libltdl/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.endif # EPEG_BUILDLINK3_MK

BUILDLINK_TREE+=	-epeg
